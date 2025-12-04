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
        l[v].push_back(u);
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

    bool helper(int v, vector<bool>& visited, int parent) {
        visited[v] = true;

        for (auto i : l[v]) {
            if (!visited[i]) {
                if (helper(i, visited, v))   
                    return true;
            } else {
                if (i != parent)
                    return true;
            }
        }
        return false;
    }


    bool isCyclic() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (helper(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);


    cout << (g.isCyclic() ? "Graph contains cycle\n" : "No cycle in graph\n");

    return 0;
}
