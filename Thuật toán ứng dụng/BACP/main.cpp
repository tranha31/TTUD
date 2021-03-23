#include <iostream>
#include <vector>

using namespace std;
int n, m, maxCurrentLoad, minLoad;
int c[20], dk[20][20], load[20];
vector<int> co[20], pe[20];
int dd[20];

bool Check(int su, int i){
    if(co[su].empty()) return true;
    for(int l=1; l<=i; l++){
        for(int k=0; k<pe[l].size(); k++){
            for(int q=0; q<co[su].size(); q++){
                if(pe[l].at(k) == co[su].at(q)){
                    return false;
                }
            }
        }
    }

    return true;
}

void Try(int u){
    if(u == n+1){
        minLoad = min(maxCurrentLoad, minLoad);
        return;
    }
    for(int i=1; i<=m; i++){
        if(Check(u, i)){
            pe[i].push_back(u);
            load[i] += c[u];
            int tmp = maxCurrentLoad;
            if(load[i] > maxCurrentLoad){
                maxCurrentLoad = load[i];
            }
            Try(u+1);
            maxCurrentLoad = tmp;
            pe[i].pop_back();
            load[i] -= c[u];
        }
    }
}

int main()
{
    cin >> n >> m;
    int x;
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> x;
            if(x == 1){
                co[i].push_back(j);
            }
            //dk[i][j] = x;
        }
    }

    minLoad = INT_MAX;
    maxCurrentLoad = 0;
    Try(1);
    if(minLoad == INT_MAX){
        cout << -1;
    }
    else{
        cout << minLoad;
    }
    return 0;
}
