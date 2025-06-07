#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int si,int mid,int ei){//0(n)
    int i=si;
    int j= mid + 1;
    vector<int> temp ;
     while(i <= mid && j <= ei) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);

    }
    while(j<=ei){
        temp.push_back(arr[j++]);

    }
    for(int idx=si,x=0;idx<=ei;idx++){
        arr[idx]=temp[x++];
    }
}
void mergesort(int arr[],int si,int ei){//0(nlogn)
    int mid =  si + (ei - si)/2;
    if(si>=ei){
        return;

    }
    mergesort(arr,si,mid); //0(logn) divide
    mergesort(arr,mid+1,ei);//0(logn) divide
    merge(arr,si,mid,ei);// conquer
}
void printarr(int arr[],int n){
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[] = {5,3,8,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);
printarr(arr,n-1);
return 0;
}
//day 21