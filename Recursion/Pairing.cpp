#include<iostream>
#include<vector>
#include<string>
using namespace std;
int pairing(int n){
    if(n==2 || n==1){
        return n;
    }
    return pairing(n-1) + pairing(n-2);

}
int main() {
cout<<pairing(10)<<endl;
}