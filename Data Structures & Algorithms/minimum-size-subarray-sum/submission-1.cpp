class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int left = 0,right = 0;
        int minLen = INT_MAX;
        int sum = 0;
        while(right<=n)
        {
            if(sum>=target)
            {
                minLen = min(minLen,right-left);
                sum-=nums[left];
                left++;
            }
            else
            {
                sum+=nums[right];
                right++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};