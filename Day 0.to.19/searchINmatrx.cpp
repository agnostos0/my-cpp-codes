#include <iostream>
using namespace std;
int S(int mat[][3],int key,int n,int m)
{

int st=0;
int end=n-1;
int mid = (st + end) / 2;
for(int i=0;i<n;i++){
    if (key > mat[i][m - 1]) {
        continue;
    }
    int st = 0, end = m - 1;
    while (st <= end) {
        int mid = (st + end) / 2;

        if (mat[i][mid] == key) {
            cout << "Key found at row " << i << ", column " << mid << endl;
            return true;
        }
        if (key < mat[i][mid]) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

 
}


return 0;
}
int main()
{
    int mat[3][3] = { {1,2,3},{4,5,6},{7,8,9}};
S(mat,3,3,3);
}