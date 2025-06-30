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

Node* buildBalancedBST(vector<int> data,int st,int end){
if(st>end){
    return NULL;
}
int mid = st + (end-st)/2;
Node* currnode = new Node(data[mid]);
currnode->left =  buildBalancedBST(data,st,mid-1);
currnode->right = buildBalancedBST(data,mid+1,end);
return currnode;
 }
 void inorder(Node* root,vector<int>& node){
    if(root==NULL){
 return;}
 
  inorder(root->left,node);
  node.push_back(root->data);
  inorder(root->right,node);

 }
 Node* convert(Node* root){
    vector<int> node;
    inorder(root,node);
    return buildBalancedBST(node,0,node.size()-1);
 }
  void preorder(Node* root){
    if(root==NULL){
 return;}
  cout<<root->data;
  preorder(root->left);
  preorder(root->right);

 }
int main(){ 
Node* root = new Node(6);
root->left = new Node(5);
root->left->left = new Node(4);
root->left->left->left = new Node(3);
root->right = new Node(7);
root->right->right = new Node(8);
root->right->right->right  = new Node(9);
 root = convert(root);
preorder(root);



}