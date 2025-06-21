#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Global variables (used for simplicity here)
static int idx = -1;
static int depth = 0;

// Function to build tree from vector (preorder style)
Node* buildtree(const vector<int>& data) {
    idx++;
    if (data[idx] == -1) {
        return NULL;
    }
    Node* curr = new Node(data[idx]);
    curr->left = buildtree(data);
    curr->right = buildtree(data);
    return curr;
}

int height(Node* root) {
    if (root == NULL) {
      
        return 0 ;
    }
    height(root->left);
    height(root->right);
    int currheight = max(height(root->left), height(root->right));
    return currheight + 1;
 
}
pair<int,int> dia(Node* root){//O(n)
    
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int,int> leftinfo = dia(root->left);
    pair<int,int> rightinfo = dia(root->right);
    int currdia = leftinfo.second + rightinfo.second + 1;
    int maxdia = max(currdia,max(leftinfo.first , rightinfo.first));
    int hieght = max(leftinfo.second,rightinfo.second) + 1;
    return make_pair(maxdia,hieght);
}

int main() {
    vector<int> data = {1, 2, -1, -1, 3, -1, 4, -1, -1};
    Node* root = buildtree(data);
    cout<<dia(root).first;

}
