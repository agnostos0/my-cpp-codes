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
void printinrange(Node* root,int start,int end){
if(root == NULL){
    return;
}
if(root->data >start && root->data < end){
    cout<<root->data<<" ";
    printinrange(root->left,start,end);
    printinrange(root->right,start,end);
}
else if(root->data <start)
{
    printinrange(root->right,start,end);
}
else{
    printinrange(root->left,start,end);
}

}

int main(){
vector<int> data = {5,4,3,2,9,8};
Node* root = buildBST(data);
printinrange(root,3,8);
}