#include<iostream>
using namespace std;
int x=2;
void dss()
{
     int x = 1;
    {
        int x = 5;
        cout<<::x<<endl;
    }
}

int main()
{
    dss();
   
return 0;
}