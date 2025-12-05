#include<iostream>
#include<vector>
#include <queue>
#include<list>
#include<stack>
using namespace std;

class Graph {
    int v;
    list<int>* adj;

public:
    Graph(int v) {
        this->v = v;
        adj = new list<int>[v];
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int u, int w) {
        adj[u].push_back(w);  // directed graph
    }
    void Indegree(vector<int>& indgri){
        for(int u = 0 ;u<v;u++){
            list<int> l = adj[u];
            for(int r:l){
                indgri[r]++;
            }
        }
    }
void toposort(vector<int>& indgree,queue<int>& q,vector<int>& ans){
    for(int i=0;i<indgree.size();i++){
        if(indgree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int j = q.front();
        q.pop();
        ans.push_back(j);
          
            list<int> l = adj[j];
            for(int w:l){
                indgree[w]--;
                 if (indgree[w] == 0) {
            q.push(w);   // << THIS adds new nodes
        }
            }
        

        

    }
            }


};

int main() {
    Graph g(6);
    vector<int> ans;
    g.addEdge(0, 2);
    g.addEdge(2, 5);
    g.addEdge(5, 4);
    g.addEdge(4, 1);
    g.addEdge(1, 3);

    vector<int> indgri(6,0);
    g.Indegree(indgri);
    queue<int> q;

    g.toposort(indgri,q,ans);
    for(int x:ans){
        cout<<x<<" ";
    }

    return 0;
}
