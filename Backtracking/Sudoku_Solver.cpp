#include<iostream>
using namespace std;
void printsudoku(int arr[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
bool issafe(int arr[9][9],int row,int col,int num){
    for(int i=0;i<9;i++){
        if(arr[i][col]==num){
            return false;
    }
    }
    for(int i=0;i<9;i++){
        if(arr[row][i]==num){
            return false;
    }}
    int srow = (row/3)*3;
    int scol = (col/3)*3;
for(int i=srow;i<srow+3;i++){
    for(int j=scol;j<scol+3;j++){
        if(arr[i][j]==num){
            return false;
    }
}}
return true;
}
bool sudokusolver(int arr[9][9],int row,int col){
    int nxtcol = col+1;
    int nxtrow = row;
    if(nxtcol==9)
    {
        nxtcol = 0;
        nxtrow++;
    }
    if(nxtrow==9){
    
        return true;    
    }
    if(arr[row][col]!=0)
        {
          return sudokusolver(arr,nxtrow,nxtcol);

        }
    for(int i=1;i<=9;i++){
         if(issafe(arr,row,col,i)){
            arr[row][col] = i;
        }
        if(sudokusolver(arr,nxtrow,nxtcol)){
            return true;
        }       
   
    }
    
    return false; // assume that no number will be safe then backtrack and return false until for loop ends and find right number after findin right number it will again return true
}
int main(){
    int sudoku[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};
if(sudokusolver(sudoku,0,0)){
    printsudoku(sudoku);
}

}