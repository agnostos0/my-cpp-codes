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
    ~Node(){
        if(next != NULL){        delete next;
    }}
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

    void rehash(){//O(n) 
    Node** oldtable = table;
    int oldsize = totalsize;
    totalsize = totalsize*2;
    table = new Node*[totalsize];
    for(int i =0 ;i<totalsize;i++){
        table[i] = NULL;
    }
    for(int i=0;i<oldsize;i++){
          Node* temp = oldtable[i];
          
          while(temp != NULL){
            insert(temp->value,temp->key);
            temp = temp->next;
          }
          if(oldtable[i] != NULL){
            delete oldtable[i];
          }
    }
}
    void insert(int value,string key){//O(1) for worst case O(n) becasue of rehashing
        int idx = Hashing(key);
        currsize++;
        if(table[idx] == NULL){
            table[idx] = new Node(value,key);
            double lamda = currsize /(double)totalsize;
            if(lamda > 1){//O(n)
                rehash();
            } 
    }
    else{
        Node* temp = table[idx];
        table[idx] = new Node(value,key);
        table[idx]->next = temp;

        
    }

}

};