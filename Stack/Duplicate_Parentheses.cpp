#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
bool isvaild(string str){
    stack<char> s;
    for(int i=0;i   < str.size();i++){
        if(str[i] !=')'){
            s.push(str[i]);}
            else {
                if(s.top() == '('){
               return true;
               }
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            
}}
return false;}
int main(){
    string str = "((a+ss))";
    cout<<isvaild(str);
}
