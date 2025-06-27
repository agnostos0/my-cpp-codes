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
int dist(Node* root,int n){
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }
    int left = dist(root->left,n);
    int right = dist(root->right,n);
    if(left!=-1){
        return left+1;
    }
    if(right!=-1){
        return right+1;
    }
    return -1;

}
int mindist(Node* root,int n1,int n2){
    Node* l = lca(root,n1,n2);
    cout<<l->data<<endl;
    int dist1 = dist(l,n1);
    int dist2 = dist(l,n2);
    return dist1+dist2;
}
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,9,-1,-1};
    Node* root = buildtree(data);
    int n1 = 3;
    int n2 = 9;

    cout<<mindist(root,n1,n2);
    return 0;
}
//time complexity O(n)  
//space complexity O(1)