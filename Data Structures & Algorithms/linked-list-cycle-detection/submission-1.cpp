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
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;

        if(slow == nullptr || slow->next ==nullptr || fast->next->next==nullptr)
        {
            return false;
        }

        while(slow!=nullptr and fast !=nullptr and fast->next!=nullptr) 
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
