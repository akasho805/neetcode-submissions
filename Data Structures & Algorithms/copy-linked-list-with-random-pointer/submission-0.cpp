/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {


        unordered_map<Node*,Node*> mp;

        if(head==nullptr)
        {
            return nullptr;
        }

        Node* newHead = new Node(head->val);
        mp[head] = newHead;

        Node *ptr =head->next,*ptr2=newHead;
        while(ptr!=nullptr)
        {
            Node* temp = new Node(ptr->val);
            mp[ptr] = temp;
            ptr2->next=temp;
            ptr2=ptr2->next;
            ptr=ptr->next;
        }

        ptr=head;
        ptr2=newHead;

        while(ptr!=nullptr)
        {
            ptr2->random=mp[ptr->random];
            ptr=ptr->next;
            ptr2=ptr2->next;
        }

        return newHead;

    }
};
