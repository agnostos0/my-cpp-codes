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
void getInorder(Node* root,vector<int> &node){
    if(root!=NULL){
    return;
    }
    getInorder(root->left,node);
    node.push_back(root->data);
    getInorder(root->right,node);

}
Node* Merge(Node* root1,Node* root2){
vector<int> node1;
vector<int> node2;
getInorder(root1,node1);
getInorder(root2,node2);
int i=0,j=0;
vector<int> node;
while(i<node1.size()){
    node.push_back(node1[i++]);
    
}
while(j<node2.size()){
    node.push_back(node2[j++]);
    
}
sort(node.begin(),node.end());
Node* root = buildBST(node);
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
vector<int> data1 = {5,4,3,2,9,8};
vector<int> data2 = {7,6,5,4,11,10};

Node* root1 = buildBST(data1);

Node* root2 = buildBST(data2);
Node* root3 = Merge(root1,root2);
cout << validateBST(root3,NULL,NULL);



}