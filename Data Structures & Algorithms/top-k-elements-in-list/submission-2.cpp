class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // //build freq map
        // unordered_map<int,int> freq;

        // for(int x: nums)
        // {
        //     freq[x]++;
        // }

        // //build minheap as we want to pop the smallest freq ones faster
        // //Heap keeps smallest freq at top
        // // Largest k elements remain inside heap
        // priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;

        // for(auto x: freq)
        // {
        //     //since we need to build based of freq and not element val we 
        //     // do {freq,el} instead of orginal {el.freq}
        //     pq.push({x.second,x.first}); 

        //     if(pq.size() > k)
        //     {
        //         pq.pop();
        //     }
        // }

        // vector<int> res;
        // while(!pq.empty())
        // {
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return res;

        // bucket sorting

        // create freq map
        unordered_map<int,int> freq;
        for(int x : nums)
        {
            freq[x]++;
        }

        // for bucket sort always initialise n+1 because freq will range from 1 for 1st occurrence 
        // and n if all n elements are same (dont requiree zero)
        int n = nums.size();
        //vector of vectors as same freq can be for diff el, so need to accommodate all
        vector<vector<int>> bucket(n + 1);

        //push el to bucket[freq]
        for(auto &p : freq)
        {
            bucket[p.second].push_back(p.first);
        }

        vector<int> res;
        //build result
        for(int i = n; i >= 0 && res.size() < k; i--)
        {
            //will push el starting with highest freq 1st
            // and break when size of res reaches k
            for(int x : bucket[i])
            {
                res.push_back(x);
                if(res.size() == k) break;
            }
        }

        return res;

    }
};
