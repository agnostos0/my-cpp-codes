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
bool search(string key){
     Node*   temp = root;
    for(int i = 0 ; i < key.size() ; i++){
        if(temp->children.count(key[i]) == 0){
            return false;}
        else{
            temp = temp->children[key[i]];

        }
      
        }
      return temp->endofword;
    }
};
bool helper(string s, Trie &t){
    if(s.size() == 0){
        return true;
    }
    for(int i = 0 ; i < s.size() ; i++){
        string first = s.substr(0,i+1);
        string second = s.substr(i+1);
          if(t.search(first) && helper(second,t)){
              return true;
    }
    }
    return false;
}
int main(){
    Trie t;
    t.insert("apple");
    t.insert("le");
    t.insert("cherry");
    cout<<helper("appleherry",t)<<endl;
}