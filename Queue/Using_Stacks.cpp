#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> s1;

    stack<int> s2;
    public:
    Queue(){
        
    }
    void push(int x){
        if(s1.empty()){
        s1.push(x);}
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();}
                s1.push(x);
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();}}

    }
    int front(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;

    }
     return s1.top();
    }
    void pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
        return;
        }
      s1.pop();
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
   cout<< q.front()<<endl;

    return 0;

}