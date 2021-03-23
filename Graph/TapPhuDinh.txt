#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

#define N 2003
int m, n, q;
vector<int> a[N];            //
int Assigned[N], Visited[N]; //
bool Choosed[N];             //

bool visit(int u, int Key) {
    if (Visited[u] == Key)
        return false;
    Visited[u] = Key;
    for (int v : a[u])
        if (!Assigned[v] || visit(Assigned[v], Key)) {
            Assigned[u] = v;
            Assigned[v] = u;
            return true;
        }
    return false;
}

void konig() {
    queue<int> qu;

    for (int i = 1; i <= m; ++i) if (!Assigned[i]) qu.push(i);
    for (int i = 1; i <= n; ++i) if (!Assigned[N - i]) qu.push(N - i);

    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        for (int v : a[u])
            if (!Choosed[v]) {
                Choosed[v] = true;
                qu.push(Assigned[v]);
            }
    }

    for (int i = 1; i <= m; ++i) if (Assigned[i] && !Choosed[i] && !Choosed[Assigned[i]])
        Choosed[i] = true;
}

int main() {
    scanf("%d%d%d", &m, &n, &q);
    if (m + n + q == 0)
        return 0;
    for (int i = 1; i <= q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(N - y);
        a[N - y].push_back(x);
    }

    static int cnt = 0;
    int Count = 0;
    for (int i = 1; i <= m; ++i) if (!Assigned[i]) visit(i, ++cnt);
    for (int i = 1; i <= m; ++i) if (Assigned[i]) Count++;
    cout << Count;

    konig();
    for (int i = 1; i <= m; ++i) if (Choosed[i]) printf(" r%d", i);
    for (int i = 1; i <= n; ++i) if (Choosed[N - i]) printf(" c%d", i);
    printf("\n");

    for (int i = 1; i <= m; ++i) a[i].clear();
    for (int i = 1; i <= n; ++i) a[N - i].clear();
    memset(Assigned, 0, sizeof Assigned);
    memset(Choosed, 0, sizeof Choosed);

    main();
}