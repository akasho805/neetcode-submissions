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

            //use currSum and maxSum to to track if the max is present without wrapping
            currSum = max(nums[i],currSum+nums[i]);
            maxSum = max(maxSum,currSum);

            // if using wrapping then we find minSum and then subtract from total
            currMin = min(nums[i],currMin+nums[i]);
            minSum = min(minSum,currMin);
        }

        //if all elements are -ve it will fail, that time we return the -ve closest to 0
        return (maxSum > 0) ? max(maxSum,total-minSum) : maxSum;
 
        
    }
};