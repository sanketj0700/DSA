#include <iostream>

using namespace std;


struct Node {
    int value;
    Node* next;
    
    Node(int x) {
        value = x;
        next = nullptr;
    }
    
};


void printLinkedList(struct Node* head) {
    while(head) {
        cout<<head->value<<"\n";
        head = head->next;
    }
}


int main() {
    int p;
    cin>>p;
    
    int value;
    cin>>value;
    
    Node* head = new Node(value);
    Node* temp = head;
    
    for(int i=0; i<p-1; i++) {
        cin>>value;
        Node* entry = new Node(value);
        temp->next = entry;
        temp = entry;
    }
    
    printLinkedList(head);
    
}