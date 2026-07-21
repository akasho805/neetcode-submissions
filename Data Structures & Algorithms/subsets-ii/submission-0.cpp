class Solution {
public:

    void dfs(vector<int>& nums,int i,vector<int>& subset, vector<vector<int>>& res)
    {
        if(i>=nums.size())
        {
            res.push_back(subset);
            return;
        }

        //include ith element
        subset.push_back(nums[i]);
        dfs(nums,i+1,subset,res);

        int j = i;
        while (j + 1 < nums.size() && nums[j] == nums[j + 1])
        {
            j++;
        }

        //exclude ith element
        subset.pop_back();
        dfs(nums,j+1,subset,res);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> subset;

        dfs(nums,0,subset,res);

        return res;        
    }
};




