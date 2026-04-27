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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *res =new ListNode();
        int carry=0;
        ListNode *ptr=res;

        while(l1!=nullptr or l2!=nullptr or carry)
        {
            int sum =0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;

            carry=sum/10;

            ListNode *temp = new ListNode(sum%10);
            ptr->next=temp;
            ptr = temp;
        }

        return res->next;

        // ListNode *res =new ListNode(),*p1=l1,*p2=l2;
        // ListNode *p3=res;

        // int carry=0;

        // while(p1!=nullptr and p2!=nullptr)
        // {
        //     int sum=p1->val+p2->val+carry;
        //     if(sum>9)
        //     {
        //         carry=1;
        //         sum=sum%10;
        //     }
        //     else
        //     {
        //         carry=0;
        //     }

        //     ListNode *temp = new ListNode(sum);
        //     p3->next=temp;
        //     p3 = temp;
        //     p1=p1->next;
        //     p2=p2->next;
        // }

        // while(p1!=nullptr)
        // {
        //     int sum=p1->val+carry;
        //     if(sum>9)
        //     {
        //         carry=1;
        //         sum=sum%10;
        //     }
        //     else
        //     {
        //         carry=0;
        //     }

        //     ListNode *temp = new ListNode(sum);
        //     p3->next=temp;
        //     p3 = temp;
        //     p1=p1->next;
        // }

        // while(p2!=nullptr)
        // {
        //     int sum=p2->val+carry;
        //     if(sum>9)
        //     {
        //         carry=1;
        //         sum=sum%10;
        //     }
        //     else
        //     {
        //         carry=0;
        //     }

        //     ListNode *temp = new ListNode(sum);
        //     p3->next=temp;
        //     p3 = temp;
        //     p2=p2->next;
        // }
        // if(carry)
        // {
        //     p3->next=new ListNode(1);
        // }

        // return res->next;
    }
};
