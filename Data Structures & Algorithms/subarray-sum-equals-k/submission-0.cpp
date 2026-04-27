class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp.insert({0,1});

        int n = nums.size();
        int sum = 0;
        int len = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int diff = sum - k;
            len+=mp[diff];
            mp[sum]++;
        }
        return len;
    }
};