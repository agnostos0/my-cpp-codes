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
Node* inOrderSuccessor(Node* root)
{
    while(root->left !=NULL){
   root = root->left;
     

}
return root;
}
Node* delNode(Node* root,int key){
    if(root==NULL)
    {
        return NULL;
    }
   
    if(root->data > key){
      root->left =  delNode(root->left,key);
    }
    else if(root->data < key) {
       root->right =  delNode(root->right,key);
    }
else{
   if(root->left == NULL && root->right == NULL){
     delete root;
    return NULL;
   }    
   else if(root->left == NULL  || root->right ==NULL){
     return root->left == NULL ? root->right : root->left;

   }
else{
   Node* IS = inOrderSuccessor(root->right);
    root->data = IS->data;
    root->right = delNode(root->right,IS->data);
    return root; 


}



}
return root;





}
void printinorder(Node* root){
    if(root==NULL){//inorder traversal
        return;
    }
    printinorder(root->left);//lefft
    cout<<root->data;//root
    printinorder(root->right);//right
  
}
int main(){
vector<int> data = {5,4,3,2,9,8};
Node* root = buildBST(data);
delNode(root,8);
printinorder(root);
}