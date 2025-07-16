#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;
bool validanaram(string s,string t){
    if(t.size() != s.size()) return false;
    unordered_map<char,int> m;
    for(int i=0;i<s.size();i++){
        
        if(m.count(s[i])){
        m[s[i]]++;}
        else{
            m[s[i]]=1;
        }


    }

    for(int i=0;i<t.size();i++){
        if(m.count(t[i])){
             m[t[i]]--;
             if(m.count(t[i]) == 0)
        {
        m.erase(t[i]);
        }
        }else{
            return false;
        }
    }
    return true;

}
int main(){

    string s = "race";
    string t = "care";
    cout<<validanaram(s,t)<<endl;
}