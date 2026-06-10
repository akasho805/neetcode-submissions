class Solution {
public:
    int rob(vector<int>& nums) {

        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]

        for(int i = nums.size()-1; i >= 0; i--)
        {
            int curr =
                max(nums[i] + next2,
                    next1);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};

//extra space
// class Solution {
// public:
//     vector<int> dp;

//     int dfs(vector<int>& nums, int i)
//     {
//         if(i>=nums.size())
//         {
//             return 0;
//         }

//         if(dp[i]!=-1)
//         {
//             return dp[i];
//         }

//         dp[i] = max(nums[i]+dfs(nums,i+2),dfs(nums,i+1));

//         return dp[i];
//     }

//     int rob(vector<int>& nums) {

//         dp.resize(nums.size(),-1);
//         return dfs(nums,0);
//     }
// };
