class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        int n = nums.size();
        int k = n/3;

        for(int x: nums)
        {
            freq[x]++;
        }

        vector<int> res;
        for(auto x: freq)
        {
            if(x.second > k)
            {
                res.push_back(x.first);
            }
        }

        return res;
    }
};