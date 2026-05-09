class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(int x: tasks)
        {
            freq[x]++;
        }

        priority_queue<pair<int,char>> maxH;
        for(auto x: freq)
        {
            maxH.push({x.second,x.first});
        }

        // dont need to store the char as they are nopt used, stored here fopr follow ups like building string  
        queue<pair<pair<int,char>,int>> q;
        int time = 0;

        while(maxH.size()!=0 || q.size()!=0)
        {
            if(q.size() != 0 and q.front().second <= time)
            {
                maxH.push(q.front().first);
                q.pop();
            }

            if(maxH.size()!=0)
            {
                pair<int,char>maxF = maxH.top();
                maxH.pop();
                if(maxF.first-1 != 0)
                {
                    q.push({{maxF.first-1,maxF.second},time+n+1});
                }
            }

            time++;
        }

        return time;

    }
};
