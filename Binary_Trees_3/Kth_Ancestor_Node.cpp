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
int kthancestor(Node* root,int k,int n){
    if(root==NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }
    int left = kthancestor(root->left,k,n);
    int right = kthancestor(root->right,k,n);
     int vaild = left == -1 ? right : left;
     if(vaild == k){
     cout<<root->data;
     }
    return vaild+1;

}
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,9,-1,-1};
    Node* root = buildtree(data);
    kthancestor(root,2,9);
    return 0;
}
//time complexity O(n)  
//space complexity O(1)