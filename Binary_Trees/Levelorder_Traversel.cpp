#include<iostream>
#include<vector>
#include<queue>
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
void levelordertraversel(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* currnod = q.front();
        q.pop();
        cout<<currnod->data;
        if(currnod->left != NULL)
{
    q.push(currnod->left);

}
if(currnod->right)
{
    q.push(currnod->right);
} 
}
}
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,2,-1,-1,10,30,-1,-1,40,-1,-1};
    Node* root = buildtree(data);
    levelordertraversel(root);
    return 0;
}