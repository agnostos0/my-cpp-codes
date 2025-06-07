#include<iostream>
using namespace std;
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int staircase(int arr[5][5], int n, int m, int key) {
    int row = 0;
    int col = m - 1;
    while (row < n && col >= 0) {
        if (arr[row][col] == key) {
            return arr[row][col]; // return the key instead of row and col
        }
        if (arr[row][col] > key) {
            col--;
        }
        if (arr[row][col] < key) {
            row++;
        }
    }
    return -1; // return -1 if key is not found
}

int main() {
    int arr[5][5] = {
        {10, 20, 30, 40, 100},
        {15, 25, 35, 45, 200},
        {27, 29, 37, 50, 300},
        {28, 39, 47, 60, 400},
        {31, 41, 51, 61, 500}
    };
    int result = staircase(arr, 5, 5,100 );
    if (result != -1) {
        cout << "Key found: " << result << endl;
    } else {
        cout << "Key not found" << endl;
    }
    return 0;
}