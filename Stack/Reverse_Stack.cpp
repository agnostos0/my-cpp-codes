#include<iostream>
#include<stack>
using namespace std;
void pushstbottom(stack<int> &s,int a){
    if(s.empty()){
        s.push(a);
        return;
    }
    int temp = s.top();
    s.pop();
    pushstbottom(s,a);
    s.push(temp);

}
void reverse(stack<int> &s)
{   if(s.empty()){
        return;
    }
    int temp;
    temp = s.top();
    s.pop();
    reverse(s);
    pushstbottom(s,temp);

}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverse(s);
    while(!s.empty()){
      cout<<s.top()<<endl;
      s.pop();
    }
}