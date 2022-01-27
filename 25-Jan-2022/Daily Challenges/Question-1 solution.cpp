// TIME COMPLEXITY => O(n)
// SPACE COMPLEXITY => O(n)


vector<int> getMax(vector<string> operations) {
    
    // Initiailzing 2 stacks
    stack<int> store;           // this stack will store all the entries pushed in by query type '1'
    stack<int> Maximums;        // this stack's top will be maximum value in the "store" stack at any given time
    
    
    // Initiailzing and reading in value of 'n'. 'n' is the number of queries to be processed
    int n = operations.size();
    
    
    // Initiailzing a vector "result" for storing type 3 query answers and returning
    vector<int> result;
    
    
    // Looping over 'n' times to process one query at a time
    for(int i=0; i<n; i++) {
        
        // Reading in type of the query in "type" variable
        char type = operations[i][0];
        
        // If "type" is 1, we need to push a new entry into the stack
        if(type=='1') {
            
            // Using stoi (String to Integer) function to convert the entry to be made from string to integer
            int entry = stoi(operations[i].substr(2));
            
            // Pushing the new entry to be made into "store" stack
            store.push(entry);
            
            // Checking whether "Maximums" stack is empty or not
            if(Maximums.size()) {
                // if not empty, checking and pushing appropriate entry into "Maximums" stack
                Maximums.push((Maximums.top()>entry) ? Maximums.top() : entry);
            } else {
                // if empty, pushing the new entry
                Maximums.push(entry);
            }
            
        } else if(type=='2') {        // If "type" is 2, we need to delete the top element of the stack, i.e., perform pop() operation
            // Performing pop() for both the stacks
            store.pop();
            Maximums.pop();
        } else {
            // Appending type 3 query answer
            result.push_back(Maximums.top());
        }
    }
    
    return result;
}