class Solution {
public:
    vector<vector<int>> dp;
    const int INF = 1e9;

    int dfs(vector<int>& coins, int i, int amount)
    {
        // amount formed successfully
        if(amount == 0)
        {
            return 0;
        }

        // no coins left
        if(i == coins.size())
        {
            return INF;
        }

        // invalid
        if(amount < 0)
        {
            return INF;
        }

        if(dp[i][amount] != -1)
        {
            return dp[i][amount];
        }

        // skip current coin
        int skip = dfs(coins, i + 1, amount);

        // take current coin
        int take = 1 + dfs(coins, i, amount - coins[i]);

        return dp[i][amount] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        dp.resize(n, vector<int>(amount + 1, -1));

        int ans = dfs(coins, 0, amount);

        return (ans >= INF) ? -1 : ans;
    }
};
