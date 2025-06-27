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
int transform(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = transform(root->left);
    int right = transform(root->right);
    int currold = root->data;
    root->data = left + right + root->left->data + root->right->data;
    return currold;
   



}
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,9,-1,-1};
    Node* root = buildtree(data);

}
//time complexity O(n)  
//space complexity O(1)