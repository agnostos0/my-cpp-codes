#include<iostream>
#include<string>
using namespace std;
void permutation(string s,string ans){
    int n = s.length();
   if(n==0){
    cout<<ans<<endl;
    return;
   }
   for(int i = 0; i < s.length(); i++){
    char ch = s[i];
  

    string newstr = s.substr(0,i)+s.substr(i+1);
    permutation(newstr,ans+ch);
   }
}
int main(){
    string s = "abc";
    string ans = "";
    permutation(s,ans);
}