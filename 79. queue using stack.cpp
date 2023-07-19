
class Queue {
    // Define the data members(if any) here.
    stack<int>st1;
    stack<int>st2;
    int size;
    
    public:
    Queue() {
        // Initialize your data structure here.
        size=0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
       while(!st2.empty()) {
           int val = st2.top();
           st1.push(val);
           st2.pop();
       }
       st1.push(val);
       size++;
       while(!st1.empty()) {
           int val = st1.top();
           st2.push(val);
           st1.pop();
       }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st2.empty()) {
            return -1;
        }
        int val = st2.top();
        st2.pop();
        size--;
        return val;

    }

    int peek() {
        // Implement the peek() function here.
        if(st2.empty()) {
            return -1;
        }
        int val = st2.top();
        return val;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return size==0?1:0;
    }
};
