#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;
   m["INDIA"] = 100;
   m["india"] = 12;
   m["china"] = 200;
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