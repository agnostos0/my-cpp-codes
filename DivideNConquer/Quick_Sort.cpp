#include<iostream>
#include<vector>
using namespace std;
int partition(int arr[],int si,int ei){
    int pivot=arr[ei];
    int i=si-1;
    int j=si;
    for (int j = si; j < ei; j++) {//shift all elements smaller than pivot to the left
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
swap(arr[i],arr[ei]);
return i;    
    }
    void quicksort(int arr[],int si,int ei){
        if(si>=ei){
            return;

        }
        int pivot=partition(arr,si,ei);//chose the pivot and partition the array for every partition we get a sorted array
        quicksort(arr,si,pivot-1);//lefft half
        quicksort(arr,pivot+1,ei);//right half

    }
    void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }}
    int main(){
        int arr[]={5,2,9,1,7,3};
        int n = sizeof(arr)/sizeof(arr[0]);
        quicksort(arr,0,n-1);
        printarr(arr,n);
        return 0;
    }
    //genrally time complexity 0(nlogn)
    //space complexity 0(logn)
    //worst case time complexity 0(n^2) when array is already sorted like pivot is the smallest element or the largest element than it will be worst