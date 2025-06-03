#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    
    string s1 = "bank";
    string s2 = "kanb";
    int n = s1.length();
    vector<bool> freq(100,false);
    cout<<n<<endl;
    for(int i = 0 ; i < n; i++)
    {
        int temp = s1.at(i);
       freq[100-temp] = true;
        cout<<temp<<endl;
    }
    for(int i=0 ; i <n ; i++){
        int temp = s2.at(i);
        if(freq[100-temp]==true)
        {
            continue;
        }
        else{
            cout<<"both words are not same"<<endl;
        return 0;
        }

    }
    cout<<"both words are same"<<endl;

}