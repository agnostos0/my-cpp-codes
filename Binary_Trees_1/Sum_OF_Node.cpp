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

int sum(Node* root) {
    if (root == NULL) {
      
        return 0 ;
    } 
    return  sum(root->right) + sum(root->left)+root->data;
 
}//for any question like this in binary tree think about right left and root for recursion

int main() {
    vector<int> data = {1, 2, -1, -1, 3, -1, 4, -1, -1};
    Node* root = buildtree(data);
    cout<<sum(root);

}
