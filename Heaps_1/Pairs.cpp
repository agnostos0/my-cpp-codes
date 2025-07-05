#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
struct comp{
    bool operator()(pair<string,int> &pair1,pair<string,int> &pair2){
        return pair1.second < pair2.second;
    }
};
int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,comp> ss;

    ss.push(make_pair("Rahul",344));
    ss.push(make_pair("Rohan",34));
    ss.push(make_pair("Rahul",12));
    while(!ss.empty()){
  
        cout<<ss.top().first<<" ";
        cout<<ss.top().second;
        cout<<",";
        ss.pop();

    }
}