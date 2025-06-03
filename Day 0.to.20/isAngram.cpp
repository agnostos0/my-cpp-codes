#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str1 = "car";
  string str2 = "cae";
int n = str1.length();
cout<<n<<endl;
int count[26] = {0};
for(int i = 0;i<n;i++)
{
    count[str1[i]-'a']++;
      count[str2[i]-'a']--;
}

for(int i = 0;i<26;i++)
{if(count[i] != 0){
    cout<<"false"<<i<<endl;
    break;

}
else{
    cout<<"true for"<<i<<endl;
}
    
}



}