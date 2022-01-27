// Question URL => https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/1/#

/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution
{
    public:
    
    int recursive(Node* root) {
        if(!root->next)
            return 1;
        
        return 1 + recursive(root->next);
    }
    
    int iterative(Node* root) {
        
        int count = 0;
        while(root) {
            count += 1;
            root = root->next;
        }
        
        return count;
        
    }
    
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        Node* temp = head;
        
        // Recursive approach
        // return recursive(temp);
        
        // Iterative approach
        return iterative(temp);
    
    }
};