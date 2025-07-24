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
    int freq;
    bool endofword;
    Node(){
        freq=0;
        endofword=false;
    }
};
class Trie{
    public:
    Node* root;
    
    Trie(){
        root=new Node();
    }
    void insert(string key)
    { Node* temp = root;
         for(int i = 0 ; i < key.size() ; i++){
            if(temp->children.count(key[i]) == 0 ){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq =1;


            }
            else{
                temp->children[key[i]]->freq++;
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
string getPrefix(string key){
    string prefix = "";
    Node* temp = root;
    for(int i = 0 ; i < key.size() ; i++){
        prefix = prefix + key[i];
        if(temp->children.count(key[i]) == 1){
                return prefix;
        }
        temp = temp->children[key[i]];
    }
    return prefix;

}
};

int main(){
    Trie t;
    t.insert("apple");
    t.insert("le");
    t.insert("cherry");

    cout<<t.getPrefix("cherry")<<endl;
}