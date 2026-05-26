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

    int pre_idx = 0;

    unordered_map<int, int> inorderIndex;

    TreeNode* build(vector<int>& preorder, int inLeft, int inRight)
    {
        // no nodes in this subtree
        if(inLeft > inRight)
        {
            return nullptr;
        }

        // preorder always gives root first
        int rootVal = preorder[pre_idx++];

        TreeNode* root = new TreeNode(rootVal);

        // locate root in inorder traversal
        int split = inorderIndex[rootVal];

        // build left subtree
        root->left = build(preorder, inLeft,split - 1);

        // build right subtree
        root->right = build(preorder,split + 1,inRight);

        return root;
    }

public:

    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {

        // store inorder indices for O(1) lookup
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }

        return build(preorder,0,inorder.size() - 1);
    }
};
