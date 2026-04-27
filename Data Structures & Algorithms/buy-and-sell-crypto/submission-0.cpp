class Solution {
public:
    int maxProfit(vector<int>& price) {
        int left=0,right=0;
        int n=price.size();
        int profit=0;

        while(right<n and left<n)
        {
            if(price[left]==price[right])
            {
                left=right;
                right++;
            }
            else if(price[left]>price[right])
            {
                left++;
            }
            else if(price[left]<price[right])
            {
                profit=max(profit,price[right]-price[left]);
                right++;
            }
        }
        return profit;
    }
};
