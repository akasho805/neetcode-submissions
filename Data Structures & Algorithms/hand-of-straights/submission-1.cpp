class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        //early exit
        if(n % groupSize != 0)
        {
            return false;
        }

        //create freq map
        unordered_map<int,int> freq;
        for(int i = 0;i<n;i++)
        {
            freq[hand[i]]++;
        }

        //use min Heap for finding min 
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto x: freq)
        {
            minHeap.push(x.first);
        }

        int groups = n / groupSize;
        int i = 1;
        while(i<=groups)
        {
            int el = minHeap.top();
            for(int start = el;start<=el+groupSize-1;start++)
            {
                if(freq.count(start)==0)
                {
                    return false;
                }
                else
                {
                    if(freq[start]<1)
                    {
                        return false;
                    }
                    freq[start]--;
                    if(freq[start]==0)
                    {
                        minHeap.pop();
                    }
                }
            }
            i++;
        }
        return true;
    }
};
