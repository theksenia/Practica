#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, f;
    cin >> n >> m >> s >> f;

    // Строим граф с весами:
    // прямое ребро (u->v) стоит 0, обратное (v->u) стоит 1
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, 0}); // идём как есть
        g[v].push_back({u, 1}); // нужно развернуть
    }

    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    deque<int> dq;

    dist[s] = 0;
    dq.push_front(s);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }

    cout << dist[f] << '\n';
    return 0;
}
