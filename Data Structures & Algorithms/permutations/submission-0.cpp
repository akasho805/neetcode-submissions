class Solution {
public:

    void dfs(vector<int>& nums,vector<vector<int>>& res,vector<int>& curr,vector<bool>& pick)
    {
        if(curr.size()==nums.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) 
        {
            if (!pick[i]) 
            {
                curr.push_back(nums[i]);
                pick[i] = true;
                dfs(nums,res,curr,pick);
                curr.pop_back();
                pick[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> pick(nums.size(), false);
        vector<int> curr;
        vector<vector<int>> res;
        dfs(nums,res,curr,pick);
        return res;
    }

};
