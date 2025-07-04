#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Heap{
    vector<int> vec;
    public:
    void push(int val){
        vec.push_back(val);
        int x= vec.size()-1;
        int paridx =( x - 1)/2;
        while(vec[paridx]<vec[x] && paridx > 0){
            swap(vec[x],vec[paridx]);
            x=paridx;
            paridx =( x - 1)/2;
}
    }
    void pop(){

        
    }
  };