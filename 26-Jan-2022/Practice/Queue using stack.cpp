// Question URL => https://practice.geeksforgeeks.org/problems/queue-using-stack/1/

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        // pushing the element to be queued into the main stack
        input.push(x);
    }

    int dequeue() {
        
        // since queue uses FIFO principle, the entry to be dequeued from the queue will be at the bottom of the main stack
        // to remove the bottom entry from the main stack, we pop all the elements from the main stack and add them to the output stack
        while(input.size()) {
            output.push(input.top());
            input.pop();
        }
        
        
        // since stacks use LIFO principle, the bottom-most entry of main stack will be the top-most entry of the output stack
        int result = output.top();
        output.pop();
        
        
        // we can simply store the top-mostvalue of output stack in a variable and pop it out
        // lastly, we can again pop out all the elements from the output stack one by one and push them into the main stack
        while(output.size()) {
            input.push(output.top());
            output.pop();
        }
        
        // this way, the queue's order will also be maintained and the push, pop actions can also be performed efficiently
        
        
        return result;
        
    }
};