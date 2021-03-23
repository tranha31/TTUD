#include <iostream>

using namespace std;
int n, cmin, r, res, bound, f, l;
int c[30][30], dd[30];

void Try(int v){
    if(r == 1){
        res = min(res, f+c[v][0]);
        return;
    }
    if(l == 0){
        for(int i=1; i<=n; i++){
            if(dd[i] == 0){
                l++;
                f += c[v][i];
                r--;
                dd[i] = 1;
                bound = f + r*cmin;
                if(bound < res){
                    Try(i);
                }
                dd[i] = 0;
                r++;
                f -= c[v][i];
                l--;
            }
        }
    }
    for(int i=n+1; i<=2*n; i++){
        if(dd[i] == 0){
            if(dd[i-n] == 1){
                l--;
                r--;
                dd[i] = 1;
                f += c[v][i];
                bound = f + r*cmin;
                if(bound < res){
                    Try(i);
                }
                f -= c[v][i];
                dd[i] = 0;
                r++;
                l++;
            }
        }
    }
}
int main()
{
    cin >> n;
    int x;
    cmin = INT_MAX;
    r = 2*n+1;
    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++){
            cin >> x;
            cmin = min(cmin, x);
            c[i][j] = x;
        }
    }
    l = bound = f = 0;
    res = INT_MAX;
    Try(0);
    cout << res;
    return 0;
}
