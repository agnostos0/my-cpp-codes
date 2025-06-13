#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
     data = value;
     prev=next = NULL;
    }};
class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
           tail= head = new_node;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    }
    void printll(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"<->";
            temp = temp->next;
        }
    }
    void pop_front(){
        if(head == NULL){
            return;
    }
    else{
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }}
};
int main(){
DoublyLinkedList ll;
ll.push_front(1);
ll.push_front(2);
ll.push_front(3);
ll.pop_front();
ll.printll();
return 0;
}