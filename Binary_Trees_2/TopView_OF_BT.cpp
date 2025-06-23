#include<iostream>
#include<vector>
#include<map>
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
void topview(Node* root){
    if(root==NULL){
        return;
    }
    queue<pair<Node*,int>> q;//(node,horizontal distance)
    q.push(make_pair(root,0));
    map<int,int> m;
    while(!q.empty()){
        Node* currnod = q.front().first;
        int h = q.front().second;
        q.pop();
        if(m.count(h)==0){
            m[h] = currnod->data;
        }
        if(currnod->left != NULL)
      {    

         q.push(make_pair(currnod->left,h-1));

          }
              if(currnod->right!= NULL)
          {
        q.push(make_pair(currnod->right,h+1));
        } 
}
for(auto it:m){
    cout<<it.second<<endl;
}

}

int main(){
    vector<int> data = {1,2,3,-1,-1,4,-1,2,-1,-1,10,30,-1,-1,40,-1,-1};
    Node* root = buildtree(data);
    topview(root);
    return 0;
}
//timecomplexit and spacecomplexity = O(n)