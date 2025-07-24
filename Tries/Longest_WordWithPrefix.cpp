#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*> children;
    bool endofword;
    Node(){
        endofword=false;
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string key)
    { Node* temp = root;
         for(int i = 0 ; i < key.size() ; i++){
            if(temp->children.count(key[i]) == 0 ){
                temp->children[key[i]] = new Node();


            }
            temp = temp->children[key[i]];

    }
            temp->endofword = true;

}
void longesthelper(Node* root,string& ans,string temp){
  for(auto pair : root->children){
      if(pair.second->endofword){
          temp+=  pair.first;
        if((temp.size()==ans.size()&& temp < ans) || (temp.size() > ans.size())){
            ans = temp;
    }
    longesthelper(pair.second,ans,temp);
    temp = temp.substr(0,temp.size()-1);
      }
}
}
string longest(){
    string ans = "";
   
    longesthelper(root,ans,"");
    return ans;
}
};

string longestwordwithallprefixes(vector<string> dict){
    Trie t;
    for(auto word:dict){
        t.insert(word);
    }
    return t.longest();
}
int main(){
vector<string> dict = {"a","abc","ab","apple","ap","app","appl","appl"};
 string ans = longestwordwithallprefixes(dict);
cout<<ans<<endl;
}