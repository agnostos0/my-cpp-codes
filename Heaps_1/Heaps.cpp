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
    void heapify(int i){
     if(i>=vec.size()){
        return;
     }
     int left = 2*i + 1;
     int right = 2*i + 2;
     int maxid= i;
     if(left>vec.size() && vec[left]> vec[maxid])
{
    maxid = left;
}   
         if(right>vec.size() && vec[right]> vec[maxid])
{
    maxid = right;
} 
if(maxid!=i){
    swap(vec[i],vec[maxid]);
    heapify(maxid);
}
    
}
    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
}
void top(){
  cout<<vec[0];
}
bool isempty(){
    return vec.size()==0;
}

  };
  int main(){
   Heap h;
   h.push(10);
   h.push(20);
   h.push(15);
   h.push(30);
   h.push(25);
   h.pop();
   h.top();

}