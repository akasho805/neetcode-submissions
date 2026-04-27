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

        ListNode *curr = head,*prev=nullptr;
        while (curr!=nullptr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nxt;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        // ListNode *p1 =head,*p2 =head;
        ListNode *slow =head,*fast =head;
        // int n=0;

        // while(p1!=nullptr)
        // {
        //     n++;
        //     p1=p1->next;
        // }

        // p1=head;

        // for(int i=0;i<n/2;i++)
        // {
        //     p1=p1->next;
        //     p2=p2->next;
        // }
        // p2=p2->next;
        // p1->next=nullptr;

        // p2=reverseList(p2);
        // p1=head;

        // ListNode *p3=head;

        // while(p1!=nullptr and p2!=nullptr)
        // {
        //     p1=p1->next;//save next node
        //     p3->next=p2;//link next node
        //     p3=p2;//move p31
        //     p2=p2->next;//save next node of 2ndf list
        //     p3->next=p1;//link next
        //     p3=p1;//move p3 to list1
        // }

        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        
        fast=reverseList(slow->next);
        slow->next=nullptr;
        slow=head;

        ListNode *p3=head;

        while(slow!=nullptr and fast!=nullptr)
        {
            slow=slow->next;//save next node
            p3->next=fast;//link next node
            p3=fast;//move p31
            fast=fast->next;//save next node of 2ndf list
            p3->next=slow;//link next
            p3=slow;//move p3 to list1
        }
        

    }
};
