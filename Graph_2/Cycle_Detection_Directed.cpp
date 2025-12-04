#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    ~Graph() {
        delete[] l;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
      
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "vertex " << i << ": ";
            for (auto j : l[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool helper(int v, vector<bool>& visited,vector<bool>& rpath) {
        visited[v] = true;
        rpath[v] = true;
        for (auto i : l[v]) {
            if (!visited[i]) {
                if (helper(i, visited, rpath))   
                    return true;
            } else {
                if ( rpath[i])
                    return true;
            }
        } 
        rpath[v] = false;
        return false;
    }


    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> rpath(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (helper(i, visited, rpath))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2,3);
    g.addEdge(3,4 );
    g.addEdge(4,0);


    cout << (g.isCyclic() ? "Graph contains cycle\n" : "No cycle in graph\n");

    return 0;
}
