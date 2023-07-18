// Stack class.
class Stack {
    int toppos;
    int *arr;
    int size;

public:
    Stack(int capacity) {
        this->toppos = -1;
        this->size = capacity;
        arr = new int[capacity];
    }

    void push(int num) {
        if (size - toppos > 1) {
            toppos++;
            arr[toppos] = num;
        } else {
            return;
        }
    }

    int pop() {
        if (toppos >= 0) {
            toppos--;
            return arr[toppos + 1];
        } else {
            return -1;
        }
    }

    int top() {
        if (toppos >= 0) {
            return arr[toppos];
        } else {
            return -1;
        }
    }

    int isEmpty() {
        if (toppos == -1)
            return 1;
        else
            return 0;
    }

    int isFull() {
        if (toppos == size - 1)
            return 1;
        else
            return 0;
    }
};
