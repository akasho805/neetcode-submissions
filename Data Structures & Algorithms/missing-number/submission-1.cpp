class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x:nums)
        {
            sum = sum ^ x;
        }

        for(int i =0;i<=n;i++)
        {
            sum = sum ^ i;
        }

        return sum;
        // mathematical soln which works with potential overflow
        // int n=nums.size();
        // int sum=(n*(n+1))/2;

        // for(int x:nums)
        // {
        //     sum-=x;
        // }
        // return sum;
    }
};
