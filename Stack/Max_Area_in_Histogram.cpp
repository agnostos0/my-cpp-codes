#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxarea(vector<int> arr){
    int n = arr.size();
    vector<int> nsr(n);
    stack<int> s;
    vector<int> nsl(n);
    for(int i=1;i<arr.size();i++){
        while(!s.empty() && arr[i]<=arr[s.top()]){
             s.pop();
        }
    
if(s.empty()){
    nsl[i]=i;
    }
    else{
        nsl[i]=s.top();
    }
    s.push(i);

}
while(!s.empty()){
    s.pop();
}
s.push(n-1);
for(int i=n-2;i>=0;i--){
    while(!s.empty() && arr[i]<=arr[s.top()]){
        s.pop();
    }
if(s.empty()){
    nsr[i]=n-1;
}
else{
    nsr[i]=s.top();
}
s.push(i);}
int maxarea = 0;
for(int i = 0 ; i < n ; i++){
    int width = nsr[i] - nsl[i] - 1;
    int height = arr[i];
    int area = width * height;
    maxarea = max(maxarea, area);
}
return maxarea;
    

}
int main(){
    vector<int> arr = {2,1,5,6,2,3};
    cout<<maxarea(arr)<<endl;
}