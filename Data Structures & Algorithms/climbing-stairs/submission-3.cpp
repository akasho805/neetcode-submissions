class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1 || n==0)
        {
            return 1;
        }
        
        int prev1 = 1, prev2 = 1,ans =0;

        for(int i=2;i<=n;i++)
        {
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }

        return ans;
        //extra space
        // vector<int> dp(n+1);

        // dp[0]=1;
        // dp[1]=1;

        // for(int i=2;i<=n;i++)
        // {
        //     dp[i] = dp[i-2] + dp[i-1];
        // }

        // return dp[n];

    }
};
