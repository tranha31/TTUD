#include <iostream>

using namespace std;

const int N = 1000005;
int n, a[N];
//long long ans = 0;

long long Try(int l, int r){
    if(l == r) return a[l];
    int m = (l+r)/2;
    long long ans = a[m];
    int h = a[m];
    int iL = m, iR = m;
    while(iL > l||iR<r){
        while(iL > l && a[iL-1] >= h){
            iL--;
        }
        while(iR<r && a[iR+1]>=h){
            iR++;
        }
        ans = max(ans, (long long)(iR-iL+1)*h);
        if(iL > l){
            if(iR < r){
                h = max(a[iL-1], a[iR+1]);
            }
            else{
                h = a[iL-1];
            }
        }
        else{
            if(iR < r){
                h = a[iR+1];
            }
            else{
                h = 0;
            }
        }
    }
    long long left = Try(l, m);
    long long right = Try(m+1, r);
    return max(ans, max(left, right));
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cout << Try(1, n);
    return 0;
}
