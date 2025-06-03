#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "1101";
    string b = "1011";

    string c = a | b;
    string d = a & b;
    d<<1;
    string e = c | (d<<1); 
    string sum = d & e;
    cout<<sum<<endl;
    return 0;
}