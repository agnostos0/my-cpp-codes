#include<iostream>
using namespace std;
class Queue{
int capacity;
int f,r;
int size;
int* arr;
public:
Queue(int capacity){
    this->capacity = capacity;
r = -1;
f= 0;
size = 0;
arr = new int[capacity];
}
void push(int val){
    if(size == capacity){
        cout<<"Queue is full"<<endl;
        return;}
       else {
            r = (r+1)%capacity;
            arr[r] = val;
            size++;
        }}
        void pop(){
            if(size == 0){
                cout<<"Queue is empty"<<endl;
        }else{
           size--;
           f = (f+1)%capacity;
        }}
        int front(){
            if(size == 0){
                cout<<"Queue is empty"<<endl;
                return -1;
        }
        return arr[f];
    }
    int rear(){
        if(size == 0){

             cout<<"Queue is empty"<<endl;
             return -1;
    }
        return arr[r];
    }

};
int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(33);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
}