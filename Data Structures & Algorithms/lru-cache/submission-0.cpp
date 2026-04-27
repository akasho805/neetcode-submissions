class LRUCache {
public:

    struct Node {
    int key, val;
    Node* next;
    Node* prev;
    };

    Node* head;
    Node* tail;
    int capacity;

    unordered_map<int,Node*> mp;

    LRUCache(int k) 
    {
        capacity = k;
        mp.reserve(capacity);
        head = new Node{0, 0, nullptr, nullptr};
        tail = new Node{0, 0, nullptr, nullptr};

        head->next = tail;
        tail->prev = head;
    }
    
    void insertAfterHead(Node *node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void remove(Node *node)
    {
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }
    int get(int key) {
        if(mp.contains(key))
        {
            Node *node = mp[key];
            remove(node);
            insertAfterHead(node);
            return node->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.contains(key))
        {
            Node *node = mp[key];
            node->val=value;
            remove(node);
            insertAfterHead(node);
        }
        else
        {
            Node *node = new Node(key,value,nullptr,nullptr);
            insertAfterHead(node);
            mp[key] = node;

            if (mp.size() > capacity) 
            {
                Node *lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
            }
        }
    }
};
