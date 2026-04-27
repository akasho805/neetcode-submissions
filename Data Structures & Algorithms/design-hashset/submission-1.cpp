class MyHashSet {
private:
    static const int SIZE = 1000;
    vector<list<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE);
    }
    
    void add(int key) {
        int h = hash(key);
        for (int x : buckets[h]) {
            if (x == key) return;
        }
        buckets[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        buckets[h].remove(key);
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (int x : buckets[h]) {
            if (x == key) return true;
        }
        return false;
    }
};