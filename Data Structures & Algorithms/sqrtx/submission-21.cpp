class Solution {
public:
    int mySqrt(int x) {
        
        if (x==0 || x ==1)
        {
            return x;
        }


        int left=0,right=x/2;
        
        while(left<=right)
        {
            long long mid=(left+right)/2;
            long long sq =mid+mid*1LL;
            if(mid*mid == x)
            {
                return mid;
            }
            else if(mid*mid > x)
            {
                right = mid-1;
            }
            else
            {
                left = mid +1;
            }
        }
        
        return right;
    }
};