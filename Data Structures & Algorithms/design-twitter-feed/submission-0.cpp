class Twitter {

    struct Tweet {

        int tweetId;
        int time;
        Tweet* next;

        Tweet(int tweetId, int time)
        {
            this->tweetId = tweetId;
            this->time = time;
            this->next = nullptr;
        }
    };

    int timer;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> latest tweet head
    unordered_map<int, Tweet*> tweets;

public:

    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {

        Tweet* newTweet = new Tweet(tweetId, timer++);

        // prepend to linked list
        newTweet->next = tweets[userId];

        tweets[userId] = newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> feed;

        // maxHeap based on timestamp
        auto cmp = [](Tweet* a, Tweet* b)
        {
            return a->time < b->time;
        };

        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> maxHeap(cmp);

        // include user's own tweets
        if(tweets.count(userId))
        {
            maxHeap.push(tweets[userId]);
        }

        // include followees' latest tweets
        for(int followee : following[userId])
        {
            if(tweets.count(followee))
            {
                maxHeap.push(tweets[followee]);
            }
        }

        while(!maxHeap.empty() && feed.size() < 10)
        {
            Tweet* curr = maxHeap.top();
            maxHeap.pop();

            feed.push_back(curr->tweetId);

            // push next older tweet from same user
            if(curr->next)
            {
                maxHeap.push(curr->next);
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {

        // avoid self follow
        if(followerId == followeeId)
        {
            return;
        }

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};