class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        //whe you bitwise and a range, only the common prefix will be left, rest will become 0;
        // you with ever iteration you remove 1 uncommon LSB and count ++
        // you do this until you find  matching preifx where numers will also become smae

        // now you can return left <<count or right <<count as both are same

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