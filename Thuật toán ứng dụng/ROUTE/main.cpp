#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
int n, k;
int a[110][110];
int b[110];
int cost[110][110];
int m, sum = 0;
int MIN = INT_MAX;
int trace[110];
bool dd[110];

void Try(int k){
    if(k == m){
        if(cost[trace[k-1]][k] != 0){
            sum += cost[trace[k-1]][k];
            if(sum < MIN){
                MIN = sum;
            }
        }
    }
    else{
        for(int i = 2; i<=m-1; i++){
            if(!dd[i]){
                if(cost[trace[k-1]][i] != 0){
                    int tmp1 = sum;
                    sum += cost[trace[k-1]][i];
                    dd[i] = true;
                    trace[k] = i;
                    Try(k+1);
                    sum = tmp1;
                    trace[k] = 0;
                    dd[i] = false;
                }
                else{
                    continue;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    int abc[k+1];
    string s;
    getline(cin, s);
    for(int i=1; i<=k; i++){
        getline(cin, s);
        m = 1;
        for(int j=0; j<s.size(); j++){
            if(s[j] > '0' && s[j] <= '9'){
                b[m] = s[j] - '0';
                m++;
            }
        }
        m--;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                cost[i][j] = a[b[i]][b[j]];
            }
        }
        trace[1] = 1;
        trace[m] = m;
        Try(2);
        if(MIN < INT_MAX){
            abc[i] = MIN;
        }
        else{
            abc[i] = 0;
        }
        MIN = INT_MAX;
        memset(trace, 0, sizeof(trace));
        memset(dd, false, sizeof(dd));
        memset(b, 0, sizeof(b));
        for(int i=1; i<=110; i++){
            for(int j=1; j<=110; j++){
                cost[i][j] = 0;
            }
        }
        sum = 0;
    }
    for(int i=1; i<=k; i++){
        cout << abc[i] << endl;
    }
    return 0;
}
