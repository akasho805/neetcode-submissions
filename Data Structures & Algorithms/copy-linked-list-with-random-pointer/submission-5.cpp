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

        if(head==nullptr)
        {
            return nullptr;
        }
        
        //weave nodes
        Node *ptr=head;
        while(ptr!=nullptr)
        {
            Node *temp = new Node(ptr->val);
            temp->next=ptr->next;
            ptr->next=temp;
            ptr=temp->next;
        }

        //assign random ptrs
        ptr=head;
        while(ptr!=nullptr)
        {
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
            ptr=ptr->next->next;
        }

        //seperate lists
        Node* copyHead = head->next;
        ptr=head;

        while(ptr != nullptr)
        {
            Node* copy = ptr->next;
            ptr->next = copy->next;  

            if(copy->next)
            {
                copy->next = copy->next->next;  
            }
            ptr = ptr->next;
        }

        return copyHead;
        // using hashmaps O(n) space
        // if(head==nullptr)
        // {
        //     return nullptr;
        // }

        // unordered_map<Node*,Node*> mp;

        // // no need of ptr2 as mp[ptr] will be same what ptr2 will be pointing to

        // Node *ptr =head;
        // while(ptr!=nullptr)
        // {
        //     mp[ptr] = new Node(ptr->val);
        //     ptr=ptr->next;
        // }

        // ptr=head;

        // while(ptr!=nullptr)
        // {
        //     mp[ptr]->next=mp[ptr->next];
        //     mp[ptr]->random=mp[ptr->random];
        //     ptr=ptr->next;
        // }

        // return mp[head];

    }
};
