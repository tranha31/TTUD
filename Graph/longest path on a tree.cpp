#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
int n;
vector<pair<int, int>> adj[N];
int dis[N];

void dfs(int u, int parent){
    for(auto a : adj[u]){
        int v = a.first;
        int w = a.second;
        if(v == parent){
            continue;
        }
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<n; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }
    int farthestVertex = 0;
    dfs(1, 0);
    for(int i = 1; i<=n; i++){
        if(dis[i] > dis[farthestVertex]){
            farthestVertex = i;
        }
    }
    memset(dis, 0, sizeof dis);
    dfs(farthestVertex, 0);
    cout << *max_element(dis+1, dis+n+1) << endl;
    return 0;
}
