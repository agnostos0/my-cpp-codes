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

Node* buildBalancedBST(vector<int> data,int st,int end   ){
if(st>end){
    return NULL;
}
int mid = st + (end-st)/2;
Node* currnode = new Node(data[mid]);
currnode->left =  buildBalancedBST(data,st,mid-1);
currnode->right = buildBalancedBST(data,mid+1,end);
return currnode;
 }
 void preorder(Node* root){
    if(root==NULL){
 return;}
  cout<<root->data;
  preorder(root->left);
  preorder(root->right);

 }
int main(){ 
vector<int> data = {1,2,3,4,5,6,7};
Node* root = buildBalancedBST(data,0,data.size()- 1);
preorder(root);


}