#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
int KthSum(vector<int> nums,int k){
    int sum = 0;
    int ans= 0 ;


    unordered_map<int,int> m;
    m[0] = 1;//null subarray
for(int j = 0 ; j < nums.size() ; j++){
    sum += nums[j];
    if(m.count(sum - k)){//i to j
        ans += m[sum - k];
    }
    if(m.count(sum)){
        m[sum]++;// 0 to i-1
    }
    else{
        m[sum] = 1;
    }
}
return ans;
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 3;
    cout<<KthSum(nums,k)<<endl;
    return 0;
}