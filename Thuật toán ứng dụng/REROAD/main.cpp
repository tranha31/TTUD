#include <iostream>

using namespace std;
int dem = 0;
int a[100010];

int Reroad(int l, int r){
    if(l == r) {
        return dem;
    }
    int m = (l+r)/2;
    if(l < m && m < r){
        if(a[m-1] != a[m] && a[m+1] != a[m]){
            dem = dem + 2;
        }
        else if(a[m-1] != a[m] && a[m+1] == a[m]){
            dem++;
        }
        else if(a[m-1] == a[m] && a[m+1] != a[m]){
            dem++;
        }
    }
    if(l == m && m < r){
        if(a[m] != a[m+1]){
            dem++;
        }
    }
    if(l < m && m == r){
        if(a[m] != a[m-1]){
            dem++;
        }
    }
    if(l <= m-1){
        Reroad(l, m-1);
    }
    if(m+1 <= r){
        Reroad(m+1, r);
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int Q;
    cin >> Q;
    int vt, gt;
    while(Q--){
        cin >> vt >> gt;
        a[vt] = gt;
        cout << Reroad(1, n) +1 << "\n";
        dem = 0;
    }
    return 0;
}
