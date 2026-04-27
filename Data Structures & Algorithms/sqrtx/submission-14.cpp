class Solution {
public:
    int mySqrt(int x) {
        
        int left=0,right=x;
        
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            // long long sq =1LL*mid*mid;
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