// Question URL => https://practice.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1/

/*
  Node is defined as 
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution
{
    public:
    int count(struct node* head, int search_for)
    {
        int count = 0;
        node* temp = head;
        
        while(temp) {
            if (temp->data == search_for) {
                count++;
            }
            
            temp = temp->next;
        }
        
        return count;
    }
};