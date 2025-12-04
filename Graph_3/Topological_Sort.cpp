#include<iostream>
#include<vector>
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

    // DFS Helper
    void topoDFS(int node, vector<bool> &visited, stack<int> &st) {
        visited[node] = true;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                topoDFS(nbr, visited, st);
            }
        }

        // Push AFTER all neighbors processed
        st.push(node);
    }

    void topologicalSort() {
        vector<bool> visited(v, false);
        stack<int> st;

        // Call DFS for all unvisited nodes
        for (int i = 0; i < v; i++) {
            if (!visited[i])
                topoDFS(i, visited, st);
        }

        // Print stack contents (gives topological order)
        cout << "Topological Order: ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();
    return 0;
}
