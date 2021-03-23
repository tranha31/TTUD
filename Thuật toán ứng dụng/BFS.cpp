#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void dfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1

    while(!Q.empty()){
        int u = Q.front();
        if(!visited[u]){
            visited[u] = true;
            cout << u << endl;
        }
        if(!adj.at(u).empty()){
            int v = adj.at(u).front();
            adj.at(u).pop_front();
            if(!visited[v]){
                Q.push(v);
            }
        }
        else{
            Q.pop();
        }
    }
}

int main()
{
    vector<list<int>> a;
    a.push_back({2,5,6});
    a.push_back({1,6,3});
    a.push_back({2,4,6});
    a.push_back({3,5,6});
    a.push_back({1,4,6});
    a.push_back({1,2,3,4,5});
    dfs(a);
    return 0;
}

