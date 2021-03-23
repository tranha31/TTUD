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
long long h[20] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000,
                    20922789888000, 355687428096000, 6402373705728000, 1216451004088320000};

void Try(int m){
    long long e = h[m-2];
    for(int i=2; i<= m-1; i++){
        trace[i] = i;
    }
    for(int i=2; i<=m; i++){
        if(cost[trace[i-1]][trace[i]] != 0){
            sum += cost[trace[i-1]][trace[i]];
        }
        else{
            sum = INT_MAX;
            break;
        }
    }
    int mins = INT_MAX;
    for(long long i=1; i<=e-1; i++){
        int j = m - 2;
        while(trace[j] > trace[j+1]){
            --j;
            if(j == 1){
                break;
            }
        }
        int l = m-1;
        while(trace[j] > trace[l]){
            --l;
        }
        swap(trace[j], trace[l]);
        int l_ = j+1;
        int r = m-1;
        while(l_ < r){
            swap(trace[l_], trace[r]);
            l_++;
            r--;
        }
        int ss = 0;
        for(int f=2; f<=m; f++){
            if(cost[trace[f-1]][trace[f]] != 0){
                ss += cost[trace[f-1]][trace[f]];
            }
            else{
                ss = 0;
                break;
            }
        }
        if(ss != 0){
            if(ss < mins){
                mins = ss;
            }
        }
    }
    if(sum > mins){
        sum = mins;
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
        Try(m);
        if(sum < INT_MAX){
            abc[i] = sum;
        }
        else{
            abc[i] = 0;
        }
        //MIN = INT_MAX;
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
