class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> store;
        
        for(char c: x) {
            if(c=='}') {
                
                if(store.size()>0 && store.top()!='{') {
                    return false;
                } else if(store.size()>0) {
                    store.pop();
                } else
                    return false;
                    
            } else if(c==']') {
                
                if(store.size()>0 && store.top()!='[') {
                    return false;
                } else if(store.size()>0) {
                    store.pop();
                } else
                    return false;
                    
            } else if(c==')') {
                
                if(store.size()>0 && store.top()!='(') {
                    return false;
                } else if(store.size()>0) {
                    store.pop();
                } else
                    return false;
                    
            } else {
                store.push(c);
            }
        }
        
        return store.size()>0 ? false : true;
    }

};