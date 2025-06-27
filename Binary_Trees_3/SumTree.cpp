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
    root->data = left + right ;
    if(root->left !=NULL){
        root->data += root->right->data;
    }
     if(root->right !=NULL){
        root->data += root->right->data;
    }
    return currold;
   



}
void levelordertraversel(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* currnod = q.front();
        q.pop();
     if(currnod==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
         q.push(NULL);
        }
        else{
        cout<<currnod->data<<". ";
        if(currnod->left != NULL)
      { 
         q.push(currnod->left);

          }


          if(currnod->right!= NULL)
          {
           q.push(currnod->right);
        } }
}
}
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,9,-1,-1};
    Node* root = buildtree(data);
    transform(root);
    levelordertraversel(root);

}
