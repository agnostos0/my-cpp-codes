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
int Hashing(string key){
    int idx =0 ;
    for(int i=0;i<key.length();i++){
        idx = idx + (key[i]*key[i])%key.length();
    }
    return idx%totalsize;
}
    void rehash(){//O(n) 
        currsize = 0;
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
         
    }
    else{
        Node* temp = table[idx];
        table[idx] = new Node(value,key);
        table[idx]->next = temp;

        
    }
       double lamda = currsize /(double)totalsize;
            if(lamda > 1){//O(n)
                rehash();
            } 

}
bool exist(string key)
{ 
  int idx = Hashing(key);
  Node* temp = table[idx];
  while(temp != NULL){
    if(temp->key == key){
        return true;
  }
  temp = temp->next;
}
return false;
}
int searcH(string key)
{ 
  int idx = Hashing(key);
  Node* temp = table[idx];
  while(temp != NULL){
    if(temp->key == key){//Found
        return temp->value; 
  }
  temp = temp->next;
}
return -1;
}
void print(){
    for(int i = 0;i<totalsize;i++){
        Node* temp = table[i];
        while (temp != NULL)
        {   cout<<"Value"<<"      "<<"Key"<<endl;
            cout<<temp->value<<" - > "<<temp->key<<endl;
            temp=temp->next;
        }
    }   
    }
};
int main(){
    HashTable h(3);
    h.insert(10,"INDIA");
    h.insert(20,"USA");
    h.insert(30,"CHINA");
    h.print();
    if(h.exist("INDIA")){
        cout<<"INDIA exists"<<endl;
        cout<<"Value fot key INDIA is "<<h.searcH("INDIA")<<endl;
    }
    
}