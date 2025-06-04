#include<iostream>
using namespace std;
int tp(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return tp(n-1)+tp(n-2);
}
int main(){
    cout<<tp(10)<<endl;
}