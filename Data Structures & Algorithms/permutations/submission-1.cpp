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
            swap(nums[first], nums[i]);      // Choose
            dfs(first + 1, nums, res);       // Recurse
            swap(nums[first], nums[i]);      // Undo
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
};

// using extra boolean array
// class Solution {
// public:

//     void dfs(vector<int>& nums,vector<vector<int>>& res,vector<int>& curr,vector<bool>& pick)
//     {
//         if(curr.size()==nums.size())
//         {
//             res.push_back(curr);
//             return;
//         }

//         for (int i = 0; i < nums.size(); i++) 
//         {
//             if (!pick[i]) 
//             {
//                 curr.push_back(nums[i]);
//                 pick[i] = true;
//                 dfs(nums,res,curr,pick);
//                 curr.pop_back();
//                 pick[i] = false;
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) 
//     {
//         vector<bool> pick(nums.size(), false);
//         vector<int> curr;
//         vector<vector<int>> res;
//         dfs(nums,res,curr,pick);
//         return res;
//     }

// };
