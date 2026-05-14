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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode *ptr = root;

        // while(ptr and ptr->val!=p->val and ptr->val!=q->val)
        while(ptr)
        {
            //LCA exist in left tree
            if(p->val < ptr-> val and q->val < ptr-> val)
            {
                ptr=ptr->left;
            }
            //LCA exist in right tree
            else if(p->val > ptr-> val and q->val > ptr-> val)
            {
                ptr=ptr->right;
            }
            else
            {
                return ptr;
            }
        }
        return ptr;

    }
};
