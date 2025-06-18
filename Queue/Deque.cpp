#include<deque>
#include<iostream>
using namespace std;
class Queue{
    deque<int> q;
    public:
    void push(int x){
       q.push_back(x);
    }
    void pop(){
        q.pop_front();
    }
    int front(){
        return q.front();
    }
   bool empty(){
    return q.empty();
   }
};
class Stack{
    deque<int> q;
    public:
    void push(int x){
        q.push_back(x);

    }
    void pop(){
        q.pop_back();
    }
    int top(){
        return q.back();
    }
    bool empty(){
        return q.empty();
    }
};
int main(){
    Queue q;
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"-------"<<endl;
    while (!q.empty())
    {cout<<q.front()<<endl;
        q.pop();
        
    }
    
    
}