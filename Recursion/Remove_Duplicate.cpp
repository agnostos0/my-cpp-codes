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