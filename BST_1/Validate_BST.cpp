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
bool validateBST(Node* root,Node* max,Node* min){
    if(root==NULL){
        return true;
    }
    if(min != NULL && root->data < min->data){
        return false;
  //for check of right sub tree
    }
    if(max != NULL && root->data > max->data){
        return false;
//for checkof left sub tree
    }
    return validateBST(root->left,root,min) && validateBST(root->right,max,root);
    
}

int main(){ 
vector<int> data = {5,4,3,2,9,8};
Node* root = buildBST(data);
cout<<validateBST(root,NULL,NULL);


}