#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int value){
        data = value;
        next = NULL;

    }
    ~Node(){if(next !=NULL){
     delete next;
     next = NULL;
    }
    }
};
class LinkedList{
    
     Node* head;
     Node* tail;
     public:
     LinkedList(){
        head = NULL;
        tail = NULL;  
        }
     ~LinkedList() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }
  
    void push_front(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = tail = new_node;
    }else{
        new_node->next = head;
        head = new_node;
    }}
    void push_back(int val){
        Node* new_node = new Node(val);
        if(tail == NULL){
            head = tail = new_node;}
        else{
            tail->next = new_node;
            tail = new_node;
}
}
void printList()
{   Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
}
}
void reverse(){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;  // save next
        current->next = prev;  // reverse link
        prev = current;        // move prev forward
        current = next;        // move current forward
    }

    // After loop, prev is the new head
    tail = head;
    head = prev;
}


};

int main(){
    LinkedList ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.reverse();
    cout << "Reversed List:" << endl;
    ll.printList();
    return 0;
   
}
