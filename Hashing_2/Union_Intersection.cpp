#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void printUnion(vector<int> a,vector<int> b){
    unordered_set<int> s;
    for(int el :a){
       s.insert(el);
    }
    for(int el :b){
       s.insert(el);
    }
    for(int el :s){
        cout<<el<<" ";
    }
}
void printIntersection(vector<int> a,vector<int> b){
    unordered_set<int> s;
    for(int el :a){
        s.insert(el);}
        for(int el :b){
            if(s.find(el)!=s.end()){
                cout<<el<<" ";
            }
        }
}
int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {4,5,6,7,8};
    printUnion(a,b);
    cout<<endl;
    printIntersection(a,b);
    return 0;
    
}