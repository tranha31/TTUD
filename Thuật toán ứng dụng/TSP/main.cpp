#include <iostream>

using namespace std;
int m, n;
bool dd[21];
int f_ = INT_MAX;
int f = 0;
int C[21][21];
int x[21];
int z;
int minx = INT_MAX;

void Try(int k){
    for(int i=1; i<=n; i++){
        if(C[x[k-1]][i] == 0){
            continue;
        }
        if(!dd[i]){
            x[k] = i;
            dd[i] = true;
            f = f + C[x[k-1]][x[k]];
            if(k == n){
                if(C[x[n]][x[1]] != 0){
                    if(f + C[x[n]][x[1]] < f_){
                        f_ = f + C[x[n]][x[1]];
                    }
                }
                else{
                    f_ = INT_MAX;
                }
            }
            else{
                z = f + (n-k+1)*minx;
                if(z < f_){
                    Try(k+1);
                }
            }
            f = f - C[x[k-1]][x[k]];
            dd[i] = false;
        }
    }
}
int main()
{
    int a, b, c;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a >> b >> c;
        if(c < minx){
            minx = c;
        }
        C[a][b] = c;
    }
    for(int i=1; i<=n; i++){
        dd[i] = false;
    }
    int m = INT_MAX;

    /*x[1] = 1;
    dd[x[1]] = true;
    Try(2);*/
    cout << f_;
    return 0;
}
