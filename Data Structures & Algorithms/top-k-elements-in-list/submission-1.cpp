class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //build freq map
        unordered_map<int,int> freq;

        for(int x: nums)
        {
            freq[x]++;
        }

        //build minheap as we want to pop the smallest fre ones faster
        // so the most freq will be at bottom
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;

        for(auto x: freq)
        {
            //since we need to build based of freq and not element val we 
            // do {freq,el} instead of orginal {el.freq}
            pq.push({x.second,x.first}); 

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;


    }
};
