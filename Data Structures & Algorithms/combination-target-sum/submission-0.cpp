class Solution {
public:

    void dfs(vector<int>& nums,int i,int target,vector<int>& subset, vector<vector<int>>& res,int sum)
    {
        if(sum == target)
        {
            res.push_back(subset);
            return;
        }

        if(i>=nums.size())
        {
            return;
        }

        //include same element
        subset.push_back(nums[i]);
        sum+=nums[i];

        if(sum<=target)
        {
            dfs(nums,i,target,subset,res,sum);
        }

        //proceed for next
        subset.pop_back();
        sum-=nums[i];     
        dfs(nums,i+1,target,subset,res,sum);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        vector<int> subset;
        int sum=0;

        dfs(nums,0,target,subset,res,sum);

        return res;

    }
};
