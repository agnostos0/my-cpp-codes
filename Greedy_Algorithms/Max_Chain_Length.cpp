#include<iostream>
#include<vector>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2 ){
    return p1.second<p2.second;
}
int max(vector<pair<int,int>> pair){
    sort(pair.begin(),pair.end(),compare);
    int n = pair.size();
    int currend = pair[0].second;
    int ans  =1;
    for(int i=1;i<n;i++){
        if(pair[i].first>currend){
ans++;
currend = pair[i].second;
        }
        
    }
    return ans;

}
int main(){

    vector<pair<int,int>> pair(5,make_pair(0,0));
    pair[0] = make_pair(5,24);
    pair[1] = make_pair(39,7);
    pair[2] = make_pair(5,28);
    pair[3] = make_pair(27,40);
    pair[4] = make_pair(50,90);
    cout<<max(pair)<<endl;
}