#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
void printroute(unordered_map<string,string> m){
    unordered_set<string> to;
    for(pair<string,string> i:m){

    to.insert(i.second);

    }
    string st="";
     for(pair<string,string> i:m){
        if (to.find(i.first) == to.end()){
        
            st = i.first;
        }
    }
    
    cout<<st<<"->";
    while(m.count(st)){
        cout<<m[st]<<"->";
        st=m[st];
    }        
    cout<<"end"<<endl;
    
}
int main(){

    unordered_map<string,string> m;
    m["Goa"]="Mumbai";
    m["Mumbai"]="Pune";
    m["Pune"]="panji";
    m["panji"]="Virar";
    printroute(m);

}