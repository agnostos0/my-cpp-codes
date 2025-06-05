#include<iostream>
using namespace std;
int ans(int arr[],int si,int ei,int target){
if(si>ei){
    return -1;

}
int mid=(ei-si)/2+si;
if(arr[mid]==target){
return mid;

}

//if mid is lie on line 1

if(arr[si]<=arr[mid]){//choose the right line for target by mid
    if(arr[si]<=target && target<=arr[mid])
    {
        return ans(arr,si,mid,target);//mid lie on line 1 and  target in its left half again divide

    }
    else{
        return ans(arr,mid+1,ei,target);//mid lie on line 1 and target in its right half again divide
    }

}
else{
    if(arr[ei]>=target && arr[mid]<=target){
        //right half
        return ans(arr,mid+1,ei,target);
    }
    else{
         return ans(arr,si,mid,target);
    }
}

}
int main(){
    int arr[]={1,3,5,7,9,11,13,15};
    int si=0,ei=7,target=9;
    cout<<ans(arr,si,ei,13);
}