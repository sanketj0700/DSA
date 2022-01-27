// Question URL => https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
        
        Node* ahead = head;
        Node* behind = head;
        
        // => taking the ahead pointer to n-1 steps ahead of the behind pointer.
        // => after this, we can simply move both the pointers (ahead and behind) forward together till the "ahead" pointer 
        // reaches last node of the list.
        while(n>1 && ahead) {
            ahead = ahead->next;
            n--;
        }
        
        // => in case ahead==NULL, this means that the list itself is smaller than "n".
        if(!ahead)
            return -1;
        
        // Moving both the pointers (ahead and behind) forward together until the ahead pointer reaches last node of the list.
        while(ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }
        
        // => since the distance between the "ahead" and "behind" pointers was "n-1", the node at which ehind would reach after the
        // while loop above would be the nth node from the end of the list.
        return behind->data;
        
}