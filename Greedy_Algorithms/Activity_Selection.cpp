#include<iostream>
#include<vector>
using namespace std;
void greedy(vector<int> st,vector<int> end){
 int curractvity = st[0];
 int count = 0;
 for(int i=0;i<st.size();i++){
   if(curractvity <= st[i]){
    curractvity = end[i];
    count++;
}

}
cout<<count<<endl;
}
int main(){
    vector<int> st = {10,12,20};
    vector<int> end = {20,25,30};//sorted by end time
    greedy(st,end);

}