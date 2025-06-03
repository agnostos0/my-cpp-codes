#include<iostream>
using namespace std;
int ispalindrome(char arr[],int n)
{
    int s=0,e=n-1;

    while(s<e)
    {
       if (arr[s] != arr[e]) {
            return false; // Not a palindrome
        }
        s++;
        e--;
    }
    return true;
}
int main()
{
    char arr[]="run";
    cout<<ispalindrome(arr,3)<<endl;
    return 0;

}