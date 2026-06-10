class Solution {
public:

    int rob(vector<int>& nums) {

        // if(nums.size() == 1)
        // {
        //     return nums[0];
        // }
        
        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]

        for(int i = nums.size()-1; i > 0; i--)
        {
            int curr =max(nums[i] + next2,next1);
            next2 = next1;
            next1 = curr;
        }

        // return next1;
        int next1_2 = 0; // dp[i+1]
        int next2_2 = 0; // dp[i+2]

        for(int i = nums.size()-2; i >= 0; i--)
        {
            int curr = max(nums[i] + next2_2, next1_2);

            next2_2 = next1_2;
            next1_2 = curr;
        }

        return max(nums[0],max(next1,next1_2));

    }
};

