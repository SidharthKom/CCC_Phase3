#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
bool vis[MAXN];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto v : adj[u]) {
            int w = v.second;
            if (dist[u] + w < dist[v.first]) {
                dist[v.first] = dist[u] + w;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main() {
    int n, m, p, q, t;
    cin >> n >> m >> p >> q >> t;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    dijkstra(p);

    if (dist[q] == INF) {
        cout << "-1\n";
    } else {
        cout << dist[q] << "\n";
    }

    return 0;
}
