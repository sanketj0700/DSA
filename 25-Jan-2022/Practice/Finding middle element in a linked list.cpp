// Question URL => https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/

/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        
        // returning -1 if the linked list is empty
        if(!head)
            return -1;
        
        Node* slow = head;
        Node* fast = head;
        
        // => moving "fast" pointer 2 steps ahead and "slow" pointer one step ahead every iteration while the next or next-to-next node of the
        // "fast" pointer is not NULL
        while(head->next && head->next->next) {
            head = head->next->next;
            slow = slow->next;
        }
        
        // => if the node next to the "fast" pointer is NULL, it means that the list is of odd length and the "slow" pointer will be
        // the middle element
        
        // if the node next-to-next to the "fast" pointer is NULL, it means that the list is of even length and the node next to the one the
        // "slow" pointer is pointing at will be the desired (middle) node of the list
        return (!head->next) ? slow->data : slow->next->data;
        
    }
};