#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void majority_element(vector<int> nums)
{ unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++){
        if(m.count(nums[i]) == 1){
        m[nums[i]]++;
    }
else{
    m[nums[i]]=1;
}
    }

    for(pair<int,int> p : m ){
        if(p.second > nums.size()/3){
cout<<p.first<<endl;
        }
}
    }

int main(){
    vector<int> nums = { 1, 1,1,1,1,1,2,3,4,4,4,4,4,4,4};
    majority_element(nums);
}