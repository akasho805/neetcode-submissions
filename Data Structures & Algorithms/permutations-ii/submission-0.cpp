class Solution {
public:

    void dfs(int first, vector<int>& nums, vector<vector<int>>& res)
    {
        if (first == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = first; i < nums.size(); i++)
        {
            if(i > first && nums[i] == nums[first])
            {
                continue;
            }

            swap(nums[first], nums[i]);      // Choose
            
            dfs(first + 1, nums, res);       // Recurse

        }

        for (int i = nums.size() - 1; i > first; --i) 
        {
            swap(nums[first], nums[i]);      // Undo
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
};