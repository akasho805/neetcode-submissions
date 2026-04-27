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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head->next == nullptr)
        return head;

        ListNode *p1 = head, *p2 = head->next,*temp=nullptr;

        while(p2!=nullptr)
        {
            p1->next = temp;
            temp = p1;
            p1=p2;
            p2=p2->next;
        }
        
        head = p1;
        p1->next=temp;
        return head;
    }
};
