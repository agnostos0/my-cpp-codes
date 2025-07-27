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
void dfs(int v,Graph& g,vector<bool>& visited){

g.dfshelper( v,visited);
}
void disconnected(Graph& g){
    vector<bool> visited(7,false);
    for(int i = 0; i < 7; i++){        
        if (!visited[i])
        {
        dfs(i,g,visited);
        }
        cout<<endl;
        
    }
}

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2,3 );
    
    g.addEdge(5,6);
     g.addEdge(4,6);
    
    g.addEdge(4,5);
    disconnected(g);
    
    return 0;

}