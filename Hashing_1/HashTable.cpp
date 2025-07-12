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
