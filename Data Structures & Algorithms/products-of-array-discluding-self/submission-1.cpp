class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> prod_from_right(n);
        prod_from_right[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            prod_from_right[i] = prod_from_right[i+1]*nums[i];
        }

        vector<int> res(n);

        int prod_from_left = 1;

        for(int i=0;i<n-1;i++)
        {
            res[i] = prod_from_left * prod_from_right[i+1];
            prod_from_left = prod_from_left * nums[i];
        }

        res[n-1]=prod_from_left;

        return res;
    }
};
