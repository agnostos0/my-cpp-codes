#include<queue>
#include<iostream>
using namespace std;
class Stack{
    queue<int> q1,q2;
    public:
    void push(int x){
        if(q1.empty()){
            q1.push(x);
        return;
        }
        while(!q1.empty())
{
         q2.push(q1.front());
         q1.pop();
}
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        q1.pop();
    }
    int top(){
        return q1.front();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
}