#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Info {
public:
    int sz;
    int min;
    int max;
    bool isBST;

    Info(int sz, int min, int max, bool isBST) {
        this->sz = sz;
        this->min = min;
        this->max = max;
        this->isBST = isBST;
    }
};

Info* getLargest(Node* root, int &maxsize) {
    if (root == nullptr) {
        return new Info(0, INT_MAX, INT_MIN, true);
    }

    Info* leftinfo = getLargest(root->left, maxsize);
    Info* rightinfo = getLargest(root->right, maxsize);

    int currmin = min(root->data, min(leftinfo->min, rightinfo->min));
    int currmax = max(root->data, max(leftinfo->max, rightinfo->max));
    int currsz = leftinfo->sz + rightinfo->sz + 1;

    if (leftinfo->isBST && rightinfo->isBST && root->data > leftinfo->max && root->data < rightinfo->min) {
        maxsize = max(maxsize, currsz);
        return new Info(currsz, currmin, currmax, true);
    }
    return new Info(currsz, currmin, currmax, false);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    int maxsize = 0;
    getLargest(root, maxsize);
    cout << maxsize;

    return 0;
}
