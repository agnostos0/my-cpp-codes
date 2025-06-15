#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
bool isvaild(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        char ch  = str[i];
        if(ch=='(' || ch=='{' || ch=='['){
             s.push(ch);}
            else{
                if(s.empty()){
                    return false;
                }
                else{
                    char top = s.top();
                    if(top =='(' && ch==')'||top =='{' && ch=='}'||top =='[' && ch==']'){
                        s.pop();
                }
            }
}}
if(s.empty()){
    return true;
}
return false;
}
int main(){

   string str = "({)";
   cout<<isvaild(str)<<endl;
}
