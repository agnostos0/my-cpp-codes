#include<iostream>
#include<stack>
using namespace std;
void solve(vector<int> s , vector<int> span)
{ stack<int> n;
    n.push(0);
    span[0] = 1;
    for(int i = 1 ; i<s.size();i++){
        int currprice = s[i];
        while(!n.empty() && currprice>=s[n.top()])
{
          n.pop();
}   
       if(n.empty()){
        span[i] = i+1;
       }
       else{
        int prevHigh = n.top();
        span[i] = i - prevHigh;
       }
       n.push(i);
       
 }
 for(int i=0;i<span.size();i++){
    cout<<span[i]<< " ";
 }

}
int main(){
    vector<int> s = {33,33,433,33,55};
 vector<int> span(s.size(), 0);
    solve(s,span);
   
}