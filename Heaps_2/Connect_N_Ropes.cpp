#include<iostream>
#include<queue>
using namespace std;
int minCost(vector<int> q){
    priority_queue<int,vector<int>,greater<int>> pq(q.begin(),q.end());
    int cost=0;
    while(pq.size()>1){
  int min1 = pq.top();
  pq.pop();
  int min2 = pq.top();
  pq.pop();
  cost+=min1+min2;
  pq.push(min1+min2);

    }
    return cost;

}
int main(){
vector<int> ropes= {4,3,2,6};
cout<<minCost(ropes)<<endl;

}