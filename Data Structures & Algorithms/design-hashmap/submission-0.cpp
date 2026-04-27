class MyHashMap {
public:
    struct Node {
        int key, value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    static const int SIZE = 1000;
    vector<Node*> buckets;

    MyHashMap() {
        buckets.resize(SIZE, nullptr);
    }

    int hash(int key) {
        return key % SIZE;
    }

    void put(int key, int value) {
        int idx = hash(key);
        Node* curr = buckets[idx];

        // If key exists → update
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }

        // Else insert new node at head (faster)
        Node* newNode = new Node(key, value);
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
    }

    int get(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];

        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }

        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    buckets[idx] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */