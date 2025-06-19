#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> coin = {1,2,5,10,20,50,100,500,2000};
    int amount = 4243;
    int n = coin.size() -1;
    vector<int> count(n+1,0);      
        while(amount  !=0){
              
            while(amount -coin[n]>=0){
                amount -= coin[n];
                count[n]++;
            }
            n--;}
for(int i =0 ; i<coin.size();i++){
    if(count[i]>0){
    cout<<"coin "<<coin[i]<<"="<<count[i]<<endl;}
}
    
}