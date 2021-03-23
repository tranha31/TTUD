#include <iostream>

using namespace std;
int n, m, cmin, ans;
int c[30][30], dd[30];

void Try(int u, int cnt, int cost){
    if(cnt == n){
        cost += c[u][1];
        if(cost < ans){
            ans = cost;
        }
        return;
    }
    for(int i=2; i<=n; i++){
        if(!dd[i]){
            if(cost+cmin*(n-cnt+1) < ans){
                dd[i] = 1;
                Try(i, cnt+1, cost+c[u][i]);
                dd[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    cmin = INT_MAX;
    for(int i=1; i<=m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        c[x][y] = z;
        cmin = min(cmin, z);
    }
    ans = INT_MAX;
    Try(1, 1, 0);
    cout << ans;
    return 0;
}
