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
        public:
    Node* root;
    int count;

    Trie(){
        root=new Node();
        count = 0;
    }

    void insertSuffix(string str){
        for(int i = 0 ; i < str.length(); i++){
            insert(str.substr(i));
        }
    }
    void insert(string key)
    { Node* temp = root;
         for(int i = 0 ; i < key.size() ; i++){
            if(temp->children.count(key[i]) == 0 ){
                temp->children[key[i]] = new Node();
                count++;

            }
            temp = temp->children[key[i]];

    }
            temp->endofword = true;

}




};
void printAllSubstrings(Node* node, string current) {
    for (auto& pair : node->children) {
        string next = current + pair.first;
        cout << next << endl;
        printAllSubstrings(pair.second, next);
    }
}
int main(){
    Trie t;
    t.insertSuffix("apple");
    t.insertSuffix("le");
    t.insertSuffix("cherry");
 printAllSubstrings(t.root,"");
}