class Solution {
public:
    int mySqrt(int x) {
        
        int left=0,right=x,mid;
        
        while(left<=right)
        {
            mid=left+(right-left)/2;
            long long sq =1LL*mid*mid;
            if(sq == x)
            {
                return mid;
            }
            else if(sq > x)
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