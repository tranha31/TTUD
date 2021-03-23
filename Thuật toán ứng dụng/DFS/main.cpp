#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

/*void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1

    while(!S.empty()){
        int u = S.top();
        if(!visited[u]){
            visited[u] = true;
            cout << u << endl;
        }
        if(!adj.at(u).empty()){
            int v = adj.at(u).front();
            adj.at(u).pop_front();
            if(!visited[v]){
                S.push(v);
            }
        }
        else{
            S.pop();
        }
    }
}*/

/*int main()
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
}*/
