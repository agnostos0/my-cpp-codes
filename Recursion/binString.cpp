#include<iostream>
#include<string>
using namespace std;
void bin(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
    return;
}
if(ans[ans.size() - 1] != '1'){
bin(n-1,ans + "0");
bin(n-1,ans+"1");
}
else{
    bin(n-1,ans + "0");
}

}
int main()
{string ans = "";
   bin(3,ans); 
   return 0;

}