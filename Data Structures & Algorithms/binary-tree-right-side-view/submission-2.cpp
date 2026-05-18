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




class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;

        if(root == nullptr)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();

            // process exactly one level
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }

                if(i == levelSize - 1)
                {
                    res.push_back(curr->val);
                }
            }

        }

        return res;
    }
};
