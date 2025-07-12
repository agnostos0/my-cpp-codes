#include<iostream>
#include<cmath> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    string key;
    int value;
    Node* next;
    Node(int value,string key){
        this->value = value;
        this->key = key;
        next = NULL;
    }
};
int Hashing(string key){
    int idx =0 ;
    for(int i=0;i<key.length();i++){
        idx = idx + (key[i]*key[i])%key.length();
    }
    return idx;
}
class HashTable{
    public:
    int totalsize;
    int currsize;//for rehsashing
    Node** table;
    HashTable(int size){
        currsize = 0;
        
        totalsize = size;
        table = new Node*[totalsize];
        for(int i = 0;i<totalsize;i++){
            table[i] = NULL;
        }
    }
    void insert(int value,string key){
        int idx = Hashing(key);
        currsize++;
        if(table[idx] == NULL){
            table[idx] = new Node(value,key);
    }
    else{
        Node* temp = table[idx];
        table[idx] = new Node(value,key);
        table[idx]->next = temp;

        
    }

}

};