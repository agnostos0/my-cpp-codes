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
bool Nodepath(Node* root,int n,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }
    if(Nodepath(root->left,n,path) || Nodepath(root->right,n,path)){
        return true;
    }
    path.pop_back();
    return false;
}
Node* lca(Node* root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = lca(root->left,n1,n2);
    Node* right = lca(root->right,n1,n2);
    if(left && right){
        return root;
    }
    return left!=NULL?left:right;
}
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,9,-1,-1};
    Node* root = buildtree(data);
    int n1 = 3;
    int n2 = 4;
    Node* ans= lca(root,n1,n2);
    cout<<ans->data;
    return 0;
}
//time complexity O(n)  
//space complexity O(1)