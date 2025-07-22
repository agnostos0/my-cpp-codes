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
};
int main(){
    Trie t;
    t.insert("apple");
}