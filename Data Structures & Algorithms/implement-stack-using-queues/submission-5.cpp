class MyStack {
public:

    queue<int> q1;
    // queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {

        q1.push(x);
        int n = q1.size()-1;
        while(n)
        {
            q1.push(q1.front());
            q1.pop();
            n--;
        }
    }
    
    int pop() {
        //actually no need to check this as operations are valid but still
        if(empty())
        {
            return -1;
        }

        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        if(empty())
        {
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// O(n) pop, rest O(1) and using 2 queues
// class MyStack {
// public:

//     queue<int> q1;
//     queue<int> q2;

//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q1.push(x);
//     }
    
//     int pop() {

//         if(empty())
//         {
//             return -1;
//         }

//         while(q1.size()!=1)
//         {
//             int val = q1.front();
//             q1.pop();
//             q2.push(val);
//         }

//         int popped = q1.front();
//         q1.pop();

//         q1=q2;
//         q2=queue<int>();

//         return popped;
//     }
    
//     int top() {
//         return q1.back();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */