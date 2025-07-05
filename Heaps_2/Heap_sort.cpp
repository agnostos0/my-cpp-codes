#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void heapify(int i, vector<int> &vec,int n){
     if(i>=n){
        return;
     }
     int left = 2*i + 1;
     int right = 2*i + 2;
     int maxid= i;
     if(left<n && vec[left]> vec[maxid])
{
    maxid = left;
}   
         if(right<n && vec[right]> vec[maxid])
{
    maxid = right;
} 
if(maxid!=i){
    swap(vec[i],vec[maxid]);
    heapify(maxid,vec,n);
}
    
}
void heapSort(vector<int> &vec){
    int n = vec.size();
   

    for(int i=n/2-1;i>=0;i--){
        heapify(i,vec,n);}

    for(int i = n-1;i>=0;i--){
        swap(vec[0],vec[i]);
        heapify(0,vec,i);
    }
}
int main(){
vector<int> vec = {12, 11, 13, 5, 6, 7};
heapSort(vec);
for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<endl;
}

}