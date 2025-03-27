#include <bits/stdc++.h>
using namespace std;
class Edge {
public:
   int u, v;
   long long w;
    Edge(int u, int v, long long w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int n, m;
vector<Edge> edges;
vector<long long> dist; 
bool bellman_ford(int src) {
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto edge : edges) {
            int u = edge.u;
            int v = edge.v;
            long long w = edge.w;
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        long long w = edge.w;
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
            cout << "Negative Cycle Detected" << endl;
            return false;
        }
    }
    
    return true;
}
int main() {
    cin >> n >> m;
    edges.clear();
    dist.assign(n + 1, LLONG_MAX); 
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    int src;
    cin >> src;
    if (!bellman_ford(src))
     return 0;
    int q;
    cin >> q;
    while (q--) {
        int dest;
        cin >> dest;
        if (dist[dest] == LLONG_MAX) 
            cout << "Not Possible" << endl;
        else 
            cout << dist[dest] << endl;
    }
    return 0;
}
