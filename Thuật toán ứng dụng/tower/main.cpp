#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x, y, z;
} block;
int n;
block a[600];
int maxh[600];

void input(){
    cin >> n;
    if (n == 0) exit(0);
    int x, y, z;
    for (int i = 1; i <= n; i++){
        cin >> x >> y >> z;
        a[6*i-5].x = x;
        a[6*i-5].y = y;
        a[6*i-5].z = z;
        a[6*i-4].x = x;
        a[6*i-4].y = z;
        a[6*i-4].z = y;
        a[6*i-3].x = y;
        a[6*i-3].y = x;
        a[6*i-3].z = z;
        a[6*i-2].x = y;
        a[6*i-2].y = z;
        a[6*i-2].z = x;
        a[6*i-1].x = z;
        a[6*i-1].y = x;
        a[6*i-1].z = y;
        a[6*i].x = z;
        a[6*i].y = y;
        a[6*i].z = x;
    }
}

int dp(int i){//Tim chieu cao cua toa thap voi dinh la vien i
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;
    for(int j = 1; j <= 6*n; j++){
        if (a[i].x < a[j].x && a[i].y < a[j].y ||
            a[i].x < a[j].y && a[i].y < a[j].x){
            maxh[i] = max (maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}

int main(){
    int cnt = 1;
    int res;
    while(1){
        res = 0;
        input();
        for(int i = 1; i <= 6 * n; i++){
            res = max(res, dp(i));
        }
        printf("Case %d: maximum height = %d\n", cnt++, res);
        for(int i=1; i<=6*n; i++){
            a[i].x = 0;
            a[i].y = 0;
            a[i].z = 0;
            maxh[i] = 0;
        }
    }
    return 0;
}
