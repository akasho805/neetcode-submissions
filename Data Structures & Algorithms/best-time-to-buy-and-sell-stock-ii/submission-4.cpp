class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0,n = prices.size();

        for(int i =1;i<n;i++)
        {
            if(prices[i] >= prices [i-1])
            {
                maxProfit+=prices[i]-prices[i-1];
            }
        }

        return maxProfit;

        // buying at lower and seling at peak
        // int maxProfit = 0;
        // int left = 0,right = 1;
        // int n = prices.size();

        // while(right<n)
        // {
        //     if(prices[right] >= prices [right-1])
        //     {   
        //         right++;
        //     }
        //     else
        //     {
        //         maxProfit+=prices[right-1]-prices[left];
        //         left = right;
        //         right++;
        //     }
        // }

        // maxProfit+=prices[right-1]-prices[left];
        // return maxProfit;
    }
};