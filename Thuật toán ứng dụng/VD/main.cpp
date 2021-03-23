#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int n, m, k;
vector<int> adj[N];
int side[N], kq[N];
bool is_biparite = true;

void check(int u){
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(side[v] == -1){
            side[v] = 1-side[u];
            check(v);
        }
        else if(side[u] == side[v]){
            is_biparite = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k;
    for(int j=1; j<=k; j++){
        cin >> n >> m;
        for(int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(side, -1, sizeof(side));
        for(int i=1; i<=n; i++){
            if(side[i] == -1){
                side[i] = 0;
                check(i);
            }
        }
        if(is_biparite){
            kq[j] = 1;
        }
        else{
            kq[j] = 0;
        }
        for(int i=1; i<=n; i++){
            while(!adj[i].empty()){
                adj[i].pop_back();
            }
        }
        is_biparite = true;
    }
    for(int i=1; i<=k; i++){
        cout << "Scenario #" << i << ":" << '\n';
        if(kq[i] == 1){
            cout << "No suspicious bugs found!" << '\n';
        }
        else{
            cout << "Suspicious bugs found!" << '\n';
        }
    }
    return 0;
}
