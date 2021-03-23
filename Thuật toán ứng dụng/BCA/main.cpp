#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<int> Course[35];
int dd[1000][1000];
vector<int> Teacher[100];
vector<int> GV[35];
int Load[1000];
int minLoad, maxCurrentLoad;

int Check(int j, int i){
    for(auto k : Teacher[j]){
        if(k == i){
            return 0;
        }
        if(dd[k][i] == 1){
            return 0;
        }
    }
    return 1;
}

void Try(int i){
    for(auto j : Course[i]){
        if(Check(j, i) == 1){
            Teacher[j].push_back(i);
            Load[j]++;
            /*if(Load[j] > minLoad){
                continue;
            }*/
            if(Load[j] > maxCurrentLoad){
                maxCurrentLoad = Load[j];
            }
            if(i == n){
                minLoad = maxCurrentLoad;
            }
            else{
                Try(i+1);
                Load[j]--;
                Teacher[j].pop_back();
            }
        }
    }
}


int main()
{
    cin >> m >> n;
    int k;
    for(int i=1; i<=m; i++){
        cin >> k;
        int tmp;
        for(int j=1; j<=k; j++){
            cin >> tmp;
            GV[i].push_back(tmp);
        }
    }
    int e, f;
    cin >> k;
    for(int i=1; i<=k; i++){
        cin >> e >> f;
        dd[e][f] = 1;
        dd[f][e] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(auto l : GV[j]){
                if(i == l){
                    Course[i].push_back(j);
                    break;
                }
            }
        }
    }
    minLoad = INT_MAX;
    maxCurrentLoad = 0;
    Try(1);
    cout << minLoad;
    /*if(minLoad > 0){
        cout << minLoad;
    }
    else{
        cout << -1;
    }*/
    return 0;
}
