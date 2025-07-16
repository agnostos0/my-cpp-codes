#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int isDistinct(vector<int> arr)
{ unordered_set<int> s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    for(int a : s){
        cout<<a<<endl;
    }
    cout<<"-----"<<endl;
    return s.size();

}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    cout<<isDistinct(arr)<<endl;
    return 0;
}