#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int largestLength(vector<int> arr){
    unordered_map<int,int> map;
    int sum=0;
    int ans=0;
    for(int j=0;j<arr.size();j++){
        sum += arr[j];
        if (sum == 0) {
            ans = j + 1;
        }

        if(map.count(sum)){
            ans = max(ans,j-map[sum]);
        }
        else{
            map[sum] = j;
        }
    }
    return ans;
}
int main(){
     vector<int> nums = {-1,-2,3,5,4,4,434,45,5,4};
     cout<<largestLength(nums)<<endl;

}