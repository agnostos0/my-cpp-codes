#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a = {33,44,56,783,33};
    vector<int> b = {1,2,3,4,5};

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    for(int i = 0; i<a.size();i++)
{
    ans += abs(a[i]-b[i]);
}
cout<<ans<<endl;
}