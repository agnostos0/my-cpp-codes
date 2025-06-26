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
int lca(Node* root,int n1,int n2){
    vector<int> path1;
    vector<int> path2;
    if(Nodepath(root,n1,path1) && Nodepath(root,n2,path2)){
        for(int i = 0 ; i < path1.size() && i < path2.size(); i++){
            if(path1[i] != path2[i]){
                return path1[i-1];
            }

            }

    }
return -1;
}
int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,9,-1,-1};
    Node* root = buildtree(data);
    int n1 = 3;
    int n2 = 4;
    cout<<lca(root,n1,n2)<<endl;
    return 0;
}