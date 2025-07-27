#include<iostream>
#include<vector>
#include<list>

using namespace std;
class Graph{
    int V;
    list<int>* l;
    public:

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }
    void addEdge(int u, int v){//undirected graph for directed graph use addEdgeDirected u-->v or v-->u\
                               // for weight graph use list<pair<int,int>> 
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << "vertex " <<i<< ":";
            for(auto j : l[i]){
                cout <<j<< ",";
            }
            cout << endl;
        }
    }
   void dfshelper(int v,vector<bool> &visited){
     visited[v] = true;
     cout << v << " ";
     for(auto i : l[v]){
        if(!visited[i]){
            dfshelper(i,visited);
        }
     }
   }
};
void dfs(int v,Graph& g){
vector<bool> visited(5,false);
g.dfshelper( v,visited);
}

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    dfs(0,g);
    return 0;

}