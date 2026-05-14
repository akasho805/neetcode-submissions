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

    int inorderSucc(TreeNode *root)
    {
        while(root->left!=nullptr)
        {
            root=root->left;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr)
        {
            return nullptr;
        }

        if(key < root->val)
        {
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right,key);
        }
        else
        {
            // case 1: leaf node ort single child combined
            if(root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // case 3: 2 children
            //step1: find inorder successor in right subtree and replace curr
            int succ = inorderSucc(root->right);
            root->val = succ;
            //step2: delete inorder successor from right subtree
            root->right = deleteNode(root->right,succ);
        }

        return root;
    }
};