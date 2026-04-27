class MyHashSet {
public:
    vector<bool> table;

    MyHashSet() {
        table.resize(1000001, false);
    }
    
    void add(int key) {
        table[key] = true;
    }
    
    void remove(int key) {
        table[key] = false;
    }
    
    bool contains(int key) {
        return table[key];
    }
};

// Separate Chaining (array of lists) for collision
// class MyHashSet {
// private:
//     static const int SIZE = 1000;
//     vector<list<int>> buckets;

//     int hash(int key) {
//         return key % SIZE;
//     }

// public:
//     MyHashSet() {
//         buckets.resize(SIZE);
//     }
    
//     void add(int key) {
//         int h = hash(key);
//         for (int x : buckets[h]) {
//             if (x == key) return;
//         }
//         buckets[h].push_back(key);
//     }
    
//     void remove(int key) {
//         int h = hash(key);
//         buckets[h].remove(key);
//     }
    
//     bool contains(int key) {
//         int h = hash(key);
//         for (int x : buckets[h]) {
//             if (x == key) return true;
//         }
//         return false;
//     }
// };