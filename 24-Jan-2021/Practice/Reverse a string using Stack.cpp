char* reverse(char *S, int len)
{
    stack<char> store;
    char* reversed = new char[len];
    
    for(int i=0; i<len; i++) {
        store.push(*(S+i));
    }
    
    for(int i=0; i<len; i++) {
        reversed[i] = store.top();
        store.pop();
    }
    
    return reversed;
    
}