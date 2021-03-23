#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
vector<pair<int, int>> adj[N];
int dis[N];

void dfs(int u, int parrent) {
        for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (v == parrent) {
                        continue;
                }
                dis[v] = dis[u] + w;
                dfs(v, u);
        }
}

int32_t main() {
        ios::sync_with_stdio(false); cin.tie(0);

        cin >> n;

        for (int i = 1; i < n; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
        }

        int farthestVertex = 0;

        dfs(1, 0);

        for (int i = 1; i <= n; i++) {
                if (dis[i] > dis[farthestVertex]) {
                        farthestVertex = i;
                }
        }

        memset(dis, 0, sizeof dis);

        dfs(farthestVertex, 0);

        cout << *max_element(dis + 1, dis + n + 1) << '\n';

        return 0;
}
