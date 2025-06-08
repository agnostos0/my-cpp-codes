#include<iostream>
using namespace std;
void printboard(vector<vector<char>> board)
{
    int n = board.size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }


}
bool issafe(vector<vector<char>> board,int row,int col){
    int n = board.size();
        for(int j= 0 ;j<row;j++){
            if(board[j][col]=='Q'){
                return false;
        }}
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;

        }}
         for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;

        }
    }
    return true;
    }



void nqueens(vector<vector<char>> board,int row){
     int n = board.size();
    if(row==n){
        
      printboard(board);
      cout<<endl;
return;
    }
    
        for(int j = 0;j<n;j++){
        if(issafe(board,row,j)){
      board[row][j] = 'Q';
      nqueens(board,row+1);
      board[row][j] = '.';
    }
    
}
}

int main(){
    vector<vector<char>> board;
    int n=4;
    for(int i=0;i<n;i++){
        vector<char> newrow;
        for(int j=0;j<n;j++){
            newrow.push_back('.');

        }
        board.push_back(newrow);
    }
    nqueens(board,0);
   
}