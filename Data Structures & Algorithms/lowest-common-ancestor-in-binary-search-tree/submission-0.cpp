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

        TreeNode *ptr1 = root, *ptr2 = root, *lca = root;

        while(ptr1->val == ptr2->val)
        {
            lca = ptr1;

            if(ptr1->val == p->val)
            {
                break;
            }
            else if(ptr1->val > p->val)
            {
                ptr1 = ptr1->left;
            }
            else
            {
                ptr1 = ptr1->right;
            }

            if(ptr2->val == q->val)
            {
                break;
            }
            else if(ptr2->val > q->val)
            {
                ptr2 = ptr2->left;
            }
            else
            {
                ptr2 = ptr2->right;
            }
        }

        return lca;

    }
};
