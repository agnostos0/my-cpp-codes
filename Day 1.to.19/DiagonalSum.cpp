#include <iostream>
using namespace std;
void diagonalS(int mat[][3],int n){
int sum=0;
for(int i=0;i<n;i++){
    sum += mat[i][i];
    if(i!=n-i-1){
    sum += mat[i][n-i-1];
    }

}
cout<<sum<<endl;
}
int main()
{int mat[3][3] = { {1,2,3},{4,5,6},{7,8,9}};
diagonalS(mat,3);
}