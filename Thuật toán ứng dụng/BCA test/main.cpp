#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<int> GV[100];
int dd[100][100];
int minLoad, maxCurrent;
vector<int> Course[100];
vector<int> Teacher[100];
int Load[100];
int dem = 0;
vector<int> KQ;

int Check(int j, int i){
    int OK = 0;
    for(int k=0; k<GV[j].size(); k++){
        if(i == GV[j].at(k)){
            OK = 1;
        }
    }
    if(OK == 1){
        for(auto l : Teacher[j]){
            if(l == i){
                return 0;
            }
            if(dd[i][l] == 1){
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

void Try(int i){
    if(i > n){
        //cout << "aaaa" << endl;
        if(dem == n){
            //cout << "bbbbb" << endl;
            KQ.push_back(maxCurrent);
            //minLoad = maxCurrent;
        }
    }
    else{
        for(int j=1; j<=m; j++){
            if(Check(j , i) == 1){
                //cout << "bbbbb" << endl;
                Teacher[j].push_back(i);
                int tmp = Load[j];
                Load[j]++;
                //cout << Load[j] << endl;
                int tmp2 = dem;
                dem++;
                //cout << dem << endl;
                if(Load[j] > maxCurrent){
                    maxCurrent = Load[j];
                }
                Try(i+1);
                dem = tmp2;
                Load[j] = tmp;
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
    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(auto l : GV[j]){
                if(i == l){
                    Course[i].push_back(j);
                    break;
                }
            }
        }
    }*/
    minLoad = INT_MAX;
    maxCurrent = 0;
    Try(1);
    //cout << KQ.size() << endl;
    for(int i=0; i<KQ.size(); i++){
        if(KQ.at(i) < minLoad){
            minLoad = KQ.at(i);
        }
    }
    if(minLoad == 0){
        cout << -1;
    }
    else{
        cout << minLoad;
    }
    return 0;
}
