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
void insert(int val,int pos){
     if (pos == 0) {
        push_front(val);
        return;
    }
    Node* new_node = new Node(val);
    Node* temp = head;
    for(int i = 0 ;i<pos-1;i++){
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        delete new_node;
        return;
    }
    new_node->next = temp->next;
    temp->next= new_node;

    if (new_node->next == NULL) {
        tail = new_node; // Update tail if inserted at end
    }

}
void pop_fornt(){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;


}
void pop_back(){
    if(tail == NULL){ return;
    } 
    if (head->next == NULL) {
    delete head;
    head = tail = NULL;
    return;
    }
     Node* temp = head;
   while (temp->next->next != NULL)
   {
        temp = temp->next;
   }
   delete tail;
   tail = temp;
   tail->next = NULL;
}
int findN(int key){
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if(temp->data == key){
            
            cout<<count<<endl;
            return count;
        }
        temp = temp->next;
        count++;
       
}
 return -1;
}
int size(){
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
       
}
return count;
}
void remove(int n){
     int len = size();
    if (n > len || n < 1) {
        cout << "Invalid position to remove" << endl;
        return;
    }

    // Special case: delete head
    if (n == len) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL; // list became empty
        return;
    }

        Node* temp = head;
    // Traverse to the (len - n)th node
    for (int i = 1; i < len - n; ++i) {
          temp = temp->next;
    }
    // Remove the (len - n + 1)th node
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    if (nodeToDelete == tail) tail = temp;
    nodeToDelete->next = NULL;
    delete nodeToDelete;
    
}
};

int main(){
    LinkedList ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.remove(1);
    ll.printList();
   
}
