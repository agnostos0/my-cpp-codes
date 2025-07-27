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

    
   bool dfshelper(int v,vector<bool> &visited,int dest){
     if(v == dest){
            return true;
        }
     visited[v] = true;
     for(auto i : l[v]){
       
        if(!visited[i]){
            if(dfshelper(i,visited,dest)){
                return true;
            }
        }

     }
     return false;
   }
};
bool dfs(int v,Graph& g,int dest){
    vector<bool> visited(5,false);
   return g.dfshelper( v,visited,dest);
}

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout<<dfs(0,g,4);
    return 0;

}