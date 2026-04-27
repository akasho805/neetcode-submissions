class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = left;
        for(int i = left;i<=right;i++)
        {
            res = res & i;
        }
        return res;
    }
};