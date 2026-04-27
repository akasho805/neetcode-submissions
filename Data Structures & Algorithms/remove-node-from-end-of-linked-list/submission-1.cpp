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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *p1=head,*p2=head;
        while(p1!=nullptr)
        {
            size++;
            p1=p1->next;
        }

        if(size==1)
        {
            return nullptr;
        }

        int target=size-n; 

        if (target==0)
        {
            return head->next;
        }
        p1=head;

        for(int i=1;i<target;i++)
        {
            p1=p1->next;
        }

        p2=p1->next;
        if(p2)
        {
            p1->next=p2->next;
        }
        else
        {
            p1->next=nullptr;
        }

        return head;

    }
};
