#include <bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    list<int>* adj;
    void countPathsUtil(int, int, int&);

public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

int Graph::countPaths(int s, int d)
{
    int pathCount = 0;
    countPathsUtil(s, d, pathCount);
    return pathCount;
}
void Graph::countPathsUtil(int u, int d,
                           int& pathCount)
{
    if (u == d)
        pathCount++;
    else {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            countPathsUtil(*i, d, pathCount);
    }
}
int main()
{   int n, k, m;
    int a[100][100];
    int h[100];
    int t[100];
    int sum = 0;
    cin >> n >> k;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> a[i][0] >> a[i][1];
    }
    Graph g(n);
    for(int i=0; i<m; i++){
        h[i] = a[i][0] - 1;
        t[i] = a[i][1] - 1;
        g.addEdge(h[i], t[i]);
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(g.countPaths(h[i], t[j]) == k) sum++;
        }
    }
    cout << sum;
    return 0;
}
