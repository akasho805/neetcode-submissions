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

    //o(n)
    int diameter = 0;

    int height(TreeNode* root) {
        if(!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }

    //o(n^2) soln
    // int maxHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + max(maxHeight(root->left), maxHeight(root->right));
    // }

    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(!root) return -1;

    //     int leftHeight = maxHeight(root->left);
    //     int rightHeight = maxHeight(root->right);
    //     int diameter = leftHeight + rightHeight;
    //     int sub = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));

    //     return max(diameter, sub);
    // }
};
