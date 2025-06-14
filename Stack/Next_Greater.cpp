#include<iostream>
#include<stack>
using namespace std;
void solve(vector<int> s , vector<int> &ans)
{ stack<int> n;

    for(int i = s.size() - 1 ; i>=0;i--){
    
        while(!n.empty() && s[i]>=n.top())
{
          n.pop();
}   
       if(n.empty()){
        ans[i] = -1; 
       }
       else{
       ans[i] = n.top();
       }
       n.push(s[i]);
       
 }
 

}
int main(){
    vector<int> s = {33,33,433,33,55};
    vector<int> ans(s.size(),0);
    solve(s,ans);
    for(int i=0;i<ans.size();i++){
    cout<<ans[i]<< " ";
 }
   
}