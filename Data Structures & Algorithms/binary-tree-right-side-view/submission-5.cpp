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

//dfs variant - better
class Solution {
public:

    void dfs(TreeNode* root,int depth,vector<int>& res)
    {
        if(root == nullptr)
        {
            return;
        }

        // first node visited at this depth
        // becomes the visible right-side node
        if(depth == res.size())
        {
            res.push_back(root->val);
        }

        // visit right subtree first
        dfs(root->right, depth + 1, res);

        dfs(root->left, depth + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;

        dfs(root, 0, res);

        return res;
    }
};

// using queue
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
        
//         vector<int> res;

//         if(root == nullptr)
//         {
//             return res;
//         }

//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty())
//         {
//             int levelSize = q.size();

//             // process exactly one level
//             for(int i = 0; i < levelSize; i++)
//             {
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 if(curr->left)
//                 {
//                     q.push(curr->left);
//                 }

//                 if(curr->right)
//                 {
//                     q.push(curr->right);
//                 }

//                 if(i == levelSize - 1)
//                 {
//                     res.push_back(curr->val);
//                 }
//             }

//         }

//         return res;
//     }
// };
