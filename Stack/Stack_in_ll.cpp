#include<iostream>
#include<list>
using namespace std;
template <class T>
class Stack {
     list<T> ll;
     public:
     void push(T data) {
        ll.push_back(data);
     }
     void pop() {
        if(ll.empty()) {
            cout<<"empty list"<<endl;
        }
        else {
            ll.pop_back();
        }
     }
     T top() {
        return ll.front();
     }
     bool isEmpty() {
        return ll.empty();
     }
};
int main(){
    Stack<int> s;
    s.push(1);
    
}