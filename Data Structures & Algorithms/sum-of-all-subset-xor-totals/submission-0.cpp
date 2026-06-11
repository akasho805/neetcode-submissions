class Solution {
public:

    int dfs(vector<int>& nums,int i,int curr)
    {
        if(i==nums.size())
        {
            return curr;
        }

        return dfs(nums,i+1,curr^nums[i]) + dfs(nums,i+1,curr);

    }

    int subsetXORSum(vector<int>& nums) {

        return dfs(nums,0,0);

    }
};