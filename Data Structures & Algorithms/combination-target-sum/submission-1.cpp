class Solution {
public:

    void dfs(vector<int>& nums,int i,int target,vector<int>& subset, vector<vector<int>>& res,int sum)
    {
        if(sum == target)
        {
            res.push_back(subset);
            return;
        }

        if(i>=nums.size() || sum + nums[i] > target)
        {
            return;
        }

        //include same element
        subset.push_back(nums[i]);
        dfs(nums,i,target,subset,res,sum+nums[i]);

        //proceed for next
        subset.pop_back();     
        dfs(nums,i+1,target,subset,res,sum);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        vector<int> subset;
        int sum=0;

        dfs(nums,0,target,subset,res,sum);

        return res;

    }
};
