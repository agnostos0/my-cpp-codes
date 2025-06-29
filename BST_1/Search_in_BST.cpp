#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left =right= NULL;
    }

};
Node* insert(Node* root,int value){
    if(root==NULL){
        root = new Node(value);
        return root;
    }
    else if(value<root->data){
        root->left = insert(root->left,value);
    }
    else {
        root->right = insert(root->right,value);
    }
    return root;
    
}
Node* buildBST(vector<int> data){
    Node* root = NULL;
    for(int i=0;i<data.size();i++){
        root = insert(root,data[i]);
    }
    return root;
}
bool search(Node* root,int key){
    if(root==NULL)
    {
        return false;
    }
    else if(root->data == key){
         return true;
    }
    else if(root->data > key){
        return search(root->left,key);
    }
    else {
        return search(root->right,key);
    }
}
int main(){
vector<int> data = {5,4,3,2,9,8};
Node* root = buildBST(data);
cout<<search(root,0);
}