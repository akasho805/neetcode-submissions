/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//using queue
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if(root == nullptr)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();

            vector<int> currLevel;

            // process exactly one level
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                currLevel.push_back(curr->val);

                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }
            }

            res.push_back(currLevel);
        }

        return res;
    }
};
// recursive bfs way
// class Solution {
// public:
    // void levelOrderRec(TreeNode* root, int level, vector<vector<int>>& res) 
    // {
    //     if (root == nullptr) return;

    //     // Add a new level to the result if needed
    //     if (res.size() <= level)
    //         res.push_back({});
  
    //     // Add current node's data to its corresponding level
    //     res[level].push_back(root->val);

    //     // Recur for left and right children
    //     levelOrderRec(root->left, level + 1, res);
    //     levelOrderRec(root->right, level + 1, res);
    // }

    // vector<vector<int>> levelOrder(TreeNode* root) 
    // {
    //     // Stores the result level by level
    //     vector<vector<int>> res; 
  
    //     levelOrderRec(root, 0, res);
    //     return res;
    // }
// };
