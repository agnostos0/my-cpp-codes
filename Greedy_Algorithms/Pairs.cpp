#include<vector>
#include<iostream>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
    //ascending order by end time.
}
int main(){
    vector<pair<int,int>> acctivities(5,make_pair(0,0));
    acctivities[0] = make_pair(1,2);
    acctivities[1] = make_pair(3,4);
    acctivities[2] = make_pair(5,99);
    acctivities[3] = make_pair(7,8);
    acctivities[4] = make_pair(9,10);
    for(int i = 0; i<acctivities.size();i++)
{
    cout<<acctivities[i].first<<","<<acctivities[i].second<<endl;

}
   sort(acctivities.begin(),acctivities.end(),compare);
 
 cout<<"sorted"<<endl;
   for(int i = 0; i<acctivities.size();i++)
{
    cout<<acctivities[i].first<<","<<acctivities[i].second<<endl;

}
}