#include<iostream>
#include<vector>
using namespace std;
bool compare(pair<double,int> p1,pair<double,int> p2){
    return p1.first>p2.first;
}
double fractionknapsack(vector<int> weight,vector<int> value,int W){
    int n=weight.size();
    vector<pair<double,int>> r(n,make_pair(0.0,0));
    for(int i=0;i<n;i++){
     double ratio = value[i]/(double)weight[i];
     r.push_back(make_pair(ratio,i));

    }
    sort(r.begin(),r.end(),compare);
    double ans = 0;
    for(int i =0 ;i<n;i++){
        int idx = r[i].second;
        if(weight[idx]<=W){
            ans +=value[idx];
            W-=weight[idx];
        }
        else{
            ans += W * r[i].first;
            break;

        }
    }
    return ans;
}


int main(){
vector<int> value = {20,40,10};
vector<int> weight  = {200,654,832}; 
int W = 1000;
cout<<fractionknapsack(weight,value,W);
}