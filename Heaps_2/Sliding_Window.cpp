#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void Max(vector<int> arr,int k){
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<k;i++){
     pq.push(make_pair(arr[i],i));
    }
    cout<<pq.top().first<<" "<<endl;
    for(int i=k;i<arr.size();i++){
      while(!pq.empty()&& pq.top().second<=(i-k)){
        pq.pop();

    }
    pq.push(make_pair(arr[i],i));
    cout<<pq.top().first<<" "<<endl;

}
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,};
    int k=3;
    Max(arr,k);
}