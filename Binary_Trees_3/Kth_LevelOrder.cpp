#include<iostream>
#include<vector>
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

Node* buildtree(const vector<int>& data, int& idx) {
    idx++;
    if (data[idx] == -1)
        return NULL;

    Node* currnod = new Node(data[idx]);
    currnod->left = buildtree(data, idx);
    currnod->right = buildtree(data, idx);
    return currnod;
}


void kthlevel(Node* root, int currlevel, int level) {
    if (root == NULL)
        return;

    if (currlevel == level) {
        cout << root->data << ", ";
        return;
    }

    kthlevel(root->left, currlevel + 1, level);
    kthlevel(root->right, currlevel + 1, level);
}

int main() {
vector<int> data = {1, 2, -1, -1, 3, -1, 4, -1, -1};
    int idx = -1;
    Node* root = buildtree(data, idx);
    kthlevel(root, 1, 2); 
    return 0;
}

