// Implementing a fized max-size Stack
template <typename T>
class Stack {
    
    public:
    
    int top;
    T arr[100];
    
    // constructor for initializing the stack
    Stack() {
        top = -1;
    }
    
    // Pop functionality
    T pop() {
        // true if stack is empty
        if(top==-1) {
            throw runtime_error("Cannot pop from an empty stack");
        } else {
            return arr[top--];
        }
    }
    
    
    // Push functionality
    void push(T x) {
        // true if stack is full
        if(top==99) {
            throw runtime_error("Stack is full");
        }
        arr[++top] = x;
    }
    
    
    // Function to get the value at top of the stack
    T topValue() {
        // true if stack is empty
        if(top==-1) {
            throw runtime_error("Empty stack has no attribute 'top'");
        }
        return arr[top];
    }
    
    
    // Function to get stack size
    int size() {
        return top+1;
    }
    
    
    // Function to check whether the stack is empty
    bool isEmpty() {
        return (top==-1) ? true : false;
    }
    
};