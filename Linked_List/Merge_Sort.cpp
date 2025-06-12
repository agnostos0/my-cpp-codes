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
Node* merge(Node* left, Node* right) {
    Node dummy(-1);           // Temporary node to start the merged list
    Node* tail = &dummy;      // Pointer to build the list

    while (left != NULL && right != NULL) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    // Attach any remaining nodes
    if (left != NULL) tail->next = left;
    else tail->next = right;

    return dummy.next;  // Return actual head of merged list
}

Node* split(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) prev->next = NULL;
    return slow;
}


Node* mergesort(Node* head)
{   
    if(head == NULL || head->next == NULL){
      return head;
    }
     Node* rhead=split(head);
     Node* left = mergesort(head);
     Node* right = mergesort(rhead);
     return merge(left,right);

}
};

int main(){
    LinkedList ll;
    
    ll.push_front(5);
    ll.push_front(1);
    ll.push_front(4);
    ll.push_back(2);
    ll.push_back(3);
    ll.printList();
    cout<<"---------"<<endl;
    ll.head = ll.mergesort(ll.head);
     ll.printList();
 }
