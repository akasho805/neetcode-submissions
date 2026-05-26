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

    unordered_map<int,int> inorderIndex;

    TreeNode* build(vector<int>& preorder,
                    int preStart,
                    int preEnd,
                    vector<int>& inorder,
                    int inStart,
                    int inEnd)
    {
        if(preStart > preEnd ||
           inStart > inEnd)
        {
            return nullptr;
        }

        // first preorder element is root
        int rootVal = preorder[preStart];

        TreeNode* root = new TreeNode(rootVal);

        // locate root in inorder
        int rootIndex = inorderIndex[rootVal];

        // size of left subtree
        int leftSize = rootIndex - inStart;

        // build left subtree
        root->left = build(preorder,
                           preStart + 1,
                           preStart + leftSize,
                           inorder,
                           inStart,
                           rootIndex - 1);

        // build right subtree
        root->right = build(preorder,
                            preStart + leftSize + 1,
                            preEnd,
                            inorder,
                            rootIndex + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        int n = preorder.size();

        for(int i = 0; i < n; i++)
        {
            inorderIndex[inorder[i]] = i;
        }

        return build(preorder,
                     0,
                     n - 1,
                     inorder,
                     0,
                     n - 1);
    }
};
