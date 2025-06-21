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

// Preorder traversal: root → left → right
// Tracks depth at leaf node ends
void height(Node* root, vector<int>& heights) {
    if (root == NULL) {
        heights.push_back(::depth);  // Push depth when hitting NULL
                           // Step back when returning
        return;
    }

    ::depth++;
    cout << root->data << " -> ";

    height(root->left, heights);
    height(root->right, heights);
    ::depth--;//backtracking
}

int main() {
    vector<int> data = {1, 2, -1, -1, 3, -1, 4, -1, -1};
    Node* root = buildtree(data);

    vector<int> heights;
    height(root, heights);
    cout << "NULL" << endl;  // End of traversal path print

    cout << "\nDepth at each leaf/end point:" << endl;
    for (int h : heights) {
        cout << h << endl;
    }
}
