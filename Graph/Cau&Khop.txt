#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, m;
vector<int> adj[N];
int low[N], num[N], current = 0;
int SoCau = 0;
bool Khop[N];

void find_b(int u, int p){
    int NumChild = 0;
    low[u] = num[u] = ++current;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v == p) continue;
        if(num[v] == 0){
            find_b(v, u);
            NumChild++;
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[v]){
                SoCau++;
            }
            if(u == p){
                if(NumChild >= 2){
                    Khop[u] = true;
                }
            }
            else{
                if(low[v] >= num[u]){
                    Khop[u] = true;
                }
            }
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
}

int main()
{
    cin >> n >> m;
    int x, y;
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        if(!num[i]){
            find_b(i, i);
        }
    }
    int c = 0;
    for(int i=1; i<=n; i++){
        if(Khop[i]) c++;
    }
    cout << c << " " << SoCau << endl;
    return 0;
}
