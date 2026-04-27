/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode *curr=head;
        ListNode *nxt=curr->next;
        
        while(nxt!=nullptr)
        {
            ListNode *node = new ListNode(gcd(curr->val,nxt->val));
            curr->next=node;
            node->next=nxt;
            curr=nxt;
            nxt=curr->next;
        }
        
        return head;
    }
};