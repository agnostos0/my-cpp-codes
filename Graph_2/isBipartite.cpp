#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    int v;
    list<int> *l;
    public:
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }
      ~Graph() {
        delete[] l;
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool isBipartite(){
        queue<int> q;
        vector<bool> vis(v,false);
        vector<int> color(v,-1);
        q.push(0);
        color[0] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            list<int> neighbours= l[curr];
            for(int v:neighbours){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }
                else{
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }


};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    cout<<g.isBipartite()<<endl;
}