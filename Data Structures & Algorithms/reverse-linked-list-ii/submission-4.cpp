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
    ListNode* reverseList(ListNode *start,ListNode *stop,ListNode *tail) {
        ListNode *curr=start,*prev=tail;
        while (curr!=stop)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nxt;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // ListNode *dummy = new ListNode;
        // dummy->next=head;
        ListNode dummy;
        dummy.next=head;
        
        ListNode *prev=&dummy,*rightptr=&dummy,*leftptr=nullptr;

        for(int i=1;i<left;i++)
        {
            prev=prev->next;
        }

        leftptr=prev->next;
        
        for(int i=1;i<=right;i++)
        {
            rightptr=rightptr->next;
        }

        ListNode *tail = rightptr->next;
        prev->next=reverseList(leftptr,rightptr->next,tail);

        return dummy.next;
    }
};