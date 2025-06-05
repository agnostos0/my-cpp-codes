//with int i
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void rd(string s,int n,string ans,int i,vector<bool> m){
    if(i==n){
        cout<<ans<<endl;
        return;
    }
     int c= s[i] - 'a';
    if(!m[c])
    {   m[c]= true;
         rd(s,n,ans + s[i],i+1,m);
    }else{
     rd(s,n,ans, i+1,m);
}
}
int main()
{
    string s = "hellllooohell";
    vector<bool> map(26,false);
    int n = s.size();
    string ans;
    int i = 0;
    rd(s,n,ans,i,map);
    return 0;


} 
//without int i
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void rd(string s,string ans,vector<bool> m){
    if(s.empty()){
        cout<<ans<<endl;
        return;
    }
     int c= s[s.size()-1] - 'a';
    if(!m[c])
    {   m[c]= true;
         rd(s.substr(0,s.size() - 1),ans + s[s.size() - 1],m);
    }else{
     rd(s.substr(0,s.size() - 1),ans,m);
}
}
int main()
{
    string s = "hellllooohell";
    vector<bool> map(26,false);

    string ans;
    
    rd(s,ans,map);
    return 0;


} 
