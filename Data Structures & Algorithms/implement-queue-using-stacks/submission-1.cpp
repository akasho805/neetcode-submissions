
//all operations are o(1) - this is because the costly operation peek transfers eelements very rarely
// and each elemnt moves only once to outstack in its lifetime. which makes its soln Amortized O(1) for ALL operations
class MyQueue {
public:
    stack<int> inStack, outStack;

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        peek(); // ensures outStack has elements
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
// o(n) push, rest o(1)
// class MyQueue {
// public:

//     stack<int> st1;
//     stack<int> st2;

//     MyQueue() {
        
//     }
    
//     void push(int x) {

//         while(!st1.empty())
//         {
//             st2.push(st1.top());
//             st1.pop();
//         }

//         st1.push(x);

//         while(!st2.empty())
//         {
//             st1.push(st2.top());
//             st2.pop();
//         }
        
//     }
    
//     int pop() {
//         if(empty())
//         {
//             return -1;
//         }

//         int val  = st1.top();
//         st1.pop();
//         return val;

//     }
    
//     int peek() {
//         if(empty())
//         {
//             return -1;
//         }
        
//         return st1.top();
//     }
    
//     bool empty() {
//         return st1.empty();
//     }
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */