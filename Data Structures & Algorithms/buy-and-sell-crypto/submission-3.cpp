class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 2 pointer approach
        // int left=0,right=0;
        // int n=price.size();
        // int profit=0;

        // while(right<n and left<n)
        // {
        //     if(price[left]<price[right])
        //     {
        //         profit=max(profit,price[right]-price[left]);
        //     }
        //     else
        //     {
        //         left=right;
        //     }
        //     right++;
        // }
        // return profit;

        //calculating profit everyday and minimum price so far
        int n = prices.size();
        int profit = 0;
        int buy= prices[0];
        for(int i=1;i<n;i++)
        {
            profit = max(prices[i]-buy,profit);
            buy=min(prices[i],buy);
        }
        return profit;
    
    }
};
