class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        int shift=0;
        while(left!=right)
        {
            left= left>>1;
            right = right >>1;
            shift++;
        }

        return left << shift;

        // brute force
        // int res = left;
        // for(int i = left;i<=right;i++)
        // {
        //     res = res & i;
        // }
        // return res;
    }
};