#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<pair<int,int>> acctivities(5,make_pair(0,0));
    acctivities[0] = make_pair(1,2);
    acctivities[1] = make_pair(3,4);
    acctivities[2] = make_pair(5,6);
    acctivities[3] = make_pair(7,8);
    acctivities[4] = make_pair(9,10);
    for(int i = 0; i<acctivities.size();i++)
{
    cout<<acctivities[i].first<<","<<acctivities[i].second<<endl;
    
}}