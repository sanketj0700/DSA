struct Node
{
    int data;
    struct Node *next;
}


class Solution
{
    
    // RECURSIVE FUNCTION TO REVERSE A SINGLY-LINKED LINKED LIST
    struct Node* reverse(struct Node *curr, struct Node *prev) {
        if(curr->next) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            return reverse(temp, prev);
        } else {
            curr->next = prev;
            return curr;
        }
    }
    
    public:
    
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // ITERATIVE APPROACH
        // Node* prev = NULL;
        // Node* curr = head;
        // Node* next;
        
        // while(curr) {
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        
        // return prev;
        
        
        // RECURSIVE APPROACH
        return reverse(head, NULL);
    }
    
};