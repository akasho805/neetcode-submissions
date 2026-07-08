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

        subset.push_back(nums[i]);
        dfs(nums,i+1,target,subset,res,sum+nums[i]);
        subset.pop_back();    
        while(i+1<nums.size() and nums[i+1]==nums[i])
        {
            i++;
        }
        dfs(nums,i+1,target,subset,res,sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        vector<int> subset;
        int sum=0;

        dfs(nums,0,target,subset,res,sum);
    
        return res;

    }
};
