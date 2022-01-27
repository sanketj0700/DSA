struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(! head || !head->next)
            return false;
        
        Node* fast = head->next->next;
        Node* slow = head->next;
        
        while(fast && fast->next) {
            if(fast==slow) {
                return true;
            } else {
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        
        return false;
    }
};