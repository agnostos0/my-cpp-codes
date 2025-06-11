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
      public:
     Node* head;
     Node* tail;
   
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
void isCycle(){
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    
    if(slow == fast){
        cout<<"cycle"<<endl;
        return;

}
}

cout<<"no"<<endl;
}
};


int main(){
    LinkedList ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.isCycle();
    return 0;
   
}
