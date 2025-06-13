#include<iostream>
using namespace std;
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
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = tail = NULL;
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
Node* split(Node* head) {
    if (head == NULL || head->next == NULL)
        {return head;}

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {prev->next = NULL;}
    return slow;
}
Node* reverse(Node* rhead){
    Node* prev = NULL;
    Node* current = rhead;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
}
return prev;
}
Node* zigzag(Node* head){
    Node* mid = split(head);
    Node* left = head;
    Node* right = mid;
     Node* tail;
    right = reverse(right);
    while(left != NULL && right != NULL){
        Node* rnext = right->next;
        Node* lnext = left->next;
          tail = right;
        left->next =right;
        right->next = lnext;
        left = lnext;
        right = rnext;
            
}
if (right != NULL) {
    tail->next = right;
}
return head;
}};

int main(){
    LinkedList ll;
    
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.head = ll.zigzag(ll.head);
    ll.printList();
 

}
