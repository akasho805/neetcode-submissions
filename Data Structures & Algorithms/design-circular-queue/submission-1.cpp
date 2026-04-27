class MyCircularQueue {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;
    int capacity;

    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        front = rear = nullptr;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        Node* temp = front;
        front = front->next;
        delete temp;

        size--;

        if (front == nullptr) {
            rear = nullptr;
        }

        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return front->val;
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
// using arrays
// class MyCircularQueue {
// public:
//     vector<int> q;
//     int front, rear, size, capacity;

//     MyCircularQueue(int k) {
//         capacity = k;
//         q.resize(k);
//         front = 0;
//         rear = -1;
//         size = 0;
//     }
    
//     bool enQueue(int value) {
//         if (isFull()) return false;

//         rear = (rear + 1) % capacity;
//         q[rear] = value;
//         size++;

//         return true;
//     }
    
//     bool deQueue() {
//         if (isEmpty()) return false;

//         front = (front + 1) % capacity;
//         size--;

//         return true;
//     }
    
//     int Front() {
//         if (isEmpty()) return -1;
//         return q[front];
//     }
    
//     int Rear() {
//         if (isEmpty()) return -1;
//         return q[rear];
//     }
    
//     bool isEmpty() {
//         return size == 0;
//     }
    
//     bool isFull() {
//         return size == capacity;
//     }
// };

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */