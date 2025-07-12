#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    
    s.insert(5);
    s.insert(1220);
    s.insert(53);

    s.insert(1);
    s.insert(1);
   

   
 
   if(s.find(2) != s.end()){
  cout<<"exists"<<endl;
   }
   else{
    cout<<" doesnot exists"<<endl;
   }
   for(auto el:s){
    cout<<el<<endl;
   }

}
