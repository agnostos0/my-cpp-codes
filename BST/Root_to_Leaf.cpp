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
void printpath(vector<int> path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void pathhelper(Node* root,vector<int>& path)
{
   if(root==NULL){
    return;
   }
   path.push_back(root->data);
   if(root->left == NULL && root->right==NULL){
       printpath(path);
       path.pop_back();
       return;
   }
   pathhelper(root->right,path);
   pathhelper(root->left,path);
   path.pop_back();
}
void leaftonode(Node* root){
    vector<int> path;
    pathhelper(root,path);
}

int main(){
vector<int> data = {5,4,3,2,9,8};
Node* root = buildBST(data);
leaftonode(root);
}