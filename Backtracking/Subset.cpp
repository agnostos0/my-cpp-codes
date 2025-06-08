#include<iostream>
#include<string>
using namespace std;
void printsubset(string s,string sb){
    
    if(s.empty()){
        cout<<sb<<endl;
      return;
    }
    
    printsubset(s.substr(1,s.length()-1),sb+s[0]);
    printsubset(s.substr(1,s.length()-1),sb);

}
int main(){
    string s = "xyz";
    string sb ="";
    printsubset(s,sb);
}