class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> res(n);

        // prefix (same as  prod_from_left idea)
        res[0] = 1;
        for(int i = 1; i < n; i++)
        {
            res[i] = res[i-1] * nums[i-1];
        }

        // suffix ( prod_from_right but on the fly)
        int prod_from_right = 1;

        for(int i = n-1; i >= 0; i--)
        {
            res[i] = res[i] * prod_from_right;
            prod_from_right = prod_from_right * nums[i];
        }

        return res;


        //1 extra array also can be removed if we use the nums arr for storing as in above
        // int n = nums.size();

        // vector<int> prod_from_right(n);
        // prod_from_right[n-1] = nums[n-1];

        // for(int i=n-2;i>=0;i--)
        // {
        //     prod_from_right[i] = prod_from_right[i+1]*nums[i];
        // }

        // vector<int> res(n);

        // int prod_from_left = 1;

        // for(int i=0;i<n-1;i++)
        // {
        //     res[i] = prod_from_left * prod_from_right[i+1];
        //     prod_from_left = prod_from_left * nums[i];
        // }

        // res[n-1]=prod_from_left;

        // return res;
    }
};
