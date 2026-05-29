class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxSum = nums[0], currSum =nums[0];

        int minSum = nums[0],currMin = nums[0];

        int n = nums.size();

        int total = nums[0];

        for(int i=1;i<n;i++)
        {
            total+=nums[i];

            currSum = max(nums[i],currSum+nums[i]);
            maxSum = max(maxSum,currSum);

            currMin = min(nums[i],currMin+nums[i]);
            minSum = min(minSum,currMin);
        }

        return (maxSum > 0) ? max(maxSum,total-minSum) : maxSum;
 
    }
};