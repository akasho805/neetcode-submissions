class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=INT_MIN;
        int sum=0;
        for(int x:weights)
        {
            mx = max(mx,x);
            sum+=x;
        }

        int left = mx,right = sum;

        while(left<=right)
        {
            int mid = (left+right)/2;
            int temp_days =0;
            int temp_sum =0;
            for(int w: weights)
            {
                temp_sum+=w;
                if(temp_sum>mid)
                {
                    temp_days++;
                    temp_sum=w;
                }
            }
            if(temp_days+1<=days)
            {
                right=mid-1;
            }
            else
            {
                left = mid+1;
            }
        }  
        return left;

    }
};