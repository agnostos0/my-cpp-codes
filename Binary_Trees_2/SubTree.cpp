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
bool isidentical(Node* root1,Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL)
    {
        return false;
    }
    
    if(root1->data!=root2->data){
         return false;
    }
    return isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right);

}
bool issubroot(Node* root, Node* subroot){
       if(root == NULL && subroot == NULL){//bothe are Null end of tree and sub tree
        return true;
    }else if(root == NULL || subroot == NULL)//if one is null and other is not than tree and sub tree is mismatched where it hits the base case
    {
        return false;
    }

    if(root->data == subroot->data){
        if(isidentical(root, subroot)){
            return true;
        }
    }
    bool left = issubroot(root->left,subroot);

    if(!left){
        return issubroot(root->right,subroot);

    }

    return true;//if right not returning false from that part means left is true so returning true
}

int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,2,-1,-1,10,30,-1,-1,40,-1,-1};
    Node* root = buildtree(data);
    Node* subroot = new Node(4);
   subroot->left = new Node(3);
   subroot->right = new Node(2);
    cout<<issubroot(root,subroot);
    return 0;
}