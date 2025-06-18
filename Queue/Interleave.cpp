#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int> &q){
    int n = q.size();
    queue<int> temp;
    for(int i=0;i<n/2;i++)
{
    temp.push(q.front());
    q.pop();
}
while(!temp.empty()){
   q.push(temp.front());
   temp.pop();
   q.push(q.front());
   q.pop();
}
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    interleave(q);
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
}}