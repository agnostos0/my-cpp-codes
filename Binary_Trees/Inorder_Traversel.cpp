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
static int idx = -1;
Node* buildtree(vector<int> data){
 idx++;
 if(data[idx]==-1){
    return NULL;
 }
 Node* currnod = new Node(data[idx]);
 currnod->left = buildtree(data);
 currnod->right = buildtree(data);
 return currnod;
}
void printinorder(Node* root){
    if(root==NULL){//inorder traversal
        return;
    }
    printinorder(root->left);//lefft
    cout<<root->data;//root
    printinorder(root->right);//right
  
}//left sub tree ->root<- right sub tree//
//timecomplexit and spacecomplexity = O(n)
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,2,-1,-1,10,30,-1,-1,40,-1,-1};
    Node* root = buildtree(data);
printinorder(root);
    return 0;
}