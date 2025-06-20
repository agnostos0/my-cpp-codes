#include<iostream>
#include<vector>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second>p2.second;
}
int main(){
    vector<pair<int,int>> job(4,make_pair(0,0));
    job[0] = make_pair(4,20);
    job[1] = make_pair(1,10);
    job[2] = make_pair(1,40);
    job[3] = make_pair(1,30);
    sort(job.begin(),job.end(),compare);
    int profit = job[0].second;
    int safe =  job[0].first;
     cout<<"job"<<"0"<<"="<<job[0].first<<","<<job[0].second<<endl;
    for(int i=1;i<job.size();i++)
{
     if(job[i].first>safe){
        profit+=job[i].second;
        safe = job[i].first;
        cout<<"job"<<i<<"="<<job[i].first<<","<<job[i].second<<endl;
     }
}
cout<<profit<<endl;
}