#include<iostream>
#include<stack>
using namespace std;
void pushatbottom(stack<int> &s,int a){
    if(s.empty()){
        s.push(a);
        return;
    }
    int val = s.top();
    s.pop();
    pushatbottom(s,a);
    s.push(val);
    
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    pushatbottom(s,0);
    printStack(s);
}