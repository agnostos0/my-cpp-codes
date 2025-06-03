#include<iostream>
using namespace std;
int  pow(int x,int n){
    if(n==0){
        return 1;
    }
return pow(x,n-1)*x;

}
int main(){
    int x,n;
    cout<<"Enter the base number: ";
    cin>>x;
    cout<<"Enter the power: ";
    cin>>n;
    cout<<pow(x,n);
}