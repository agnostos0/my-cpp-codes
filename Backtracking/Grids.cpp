#include<iostream>
using namespace std;
int gridways(int r,int c,int n,int m){
    if(r==n-1 && c==m-1){
      return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    return gridways(r+1,c,n,m) + gridways(r,c+1,n,m);
}
int main(){
    cout<<gridways(0,0,3,3);

}//for every we take to 2 choices, and for destination we need to pass through n-1 R and m-1 D
//so total number of ways = 2^(n-1+m-1), timecomplexity is O(2^n+m) optimize by DP to O(n*m).
//we can get optimise this by using memoization
//on every cell we have two option either move right or down
//we need to take atleast n-1 and m-1 steps to reach the destination
//_,_,_,_,_,_,_ n - 1 + m -1 for nxmgrid we need 7 steps  to fill with n-1 R and  m-1 D
