#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> m;
    m["b"] = 300;
     m["ab"] = 2;
   m["abc"] = 0;
   
  
   for(pair<string,int> country : m){
    cout<<country.first<<" , "<<country.second<<endl;
   }
   if(m.count("canada")){
  cout<<"exists"<<endl;
   }
   else{
    cout<<"canada doesnot exists"<<endl;
   }
}
//here saves lexographically  according to key values...