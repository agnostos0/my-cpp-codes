#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Edge{
    public:
int v;
int wt;
Edge(int v,int wt){
    this->v = v;
    this->wt = wt;

}
};
void Dijkstra(int src, vector<vector<Edge>> graph,int V){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0,src));
    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();
        for(Edge e:graph[u]){
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v]  = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    
    }
        cout<<"shortest distance"<<endl;
        for(int d:dist){
            cout<<d<<" "<<endl;
        }
     
}
int main(){
    int V = 6 ;
    vector<vector<Edge>> graph(V);
      
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1 ));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));


    graph[3].push_back(Edge(5,1));


    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));
    Dijkstra(0,graph,V);

  return 0; 
}