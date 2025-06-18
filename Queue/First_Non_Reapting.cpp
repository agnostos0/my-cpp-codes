#include<iostream>
#include<queue>
using namespace std;
void solve(string s){
    queue<char> q;
    int freq[26] = {0};
    for(int i = 0; i<s.size();i++)
{
    freq[s[i]-'a']++;
    q.push(s[i]);
    while(!q.empty() && freq[q.front()-'a'] >1){
        q.pop();
    }
    if(q.empty()){
        cout<<"-1"<<endl;
    }else{
        cout<<q.front()<<endl;
    }


}
};
int main(){
    string s;
    s = "aaaabsdwefthbssbx";
    solve(s);
}
