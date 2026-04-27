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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newHead = new ListNode();

        ListNode *p1=list1,*p2=list2,*p3=newHead;

        while(p1!= nullptr and p2!= nullptr)
        {
            if(p1->val <= p2->val)
            {
                ListNode *temp = new ListNode(p1->val);
                p3->next =temp;
                p3 = temp;
                p1 = p1->next;
            }
            else
            {   
                ListNode *temp = new ListNode(p2->val);
                p3->next =temp;
                p3 = temp;
                p2 = p2->next;
            }
        }

        while(p1!= nullptr)
        {
            ListNode *temp = new ListNode(p1->val);
            p3->next =temp;
            p3 = temp;
            p1 = p1->next;
        }
        while(p2!= nullptr)
        {
            ListNode *temp = new ListNode(p2->val);
            p3->next =temp;
            p3 = temp;
            p2 = p2->next;
        }

        return newHead->next;

    }
};
