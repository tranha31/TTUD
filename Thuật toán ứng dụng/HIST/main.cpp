#include <iostream>
#include <algorithm>

using namespace std;
long long a[1000002];

long long Hist(int l, int r){
    if(l == r){
        return a[l];
    }
    int m = (l+r)/2;
    int ileft = m;
    int iright = m;
    int h = a[m];
    long long maxS = a[m];
    while(ileft > l || iright < r){
        while(ileft > l && a[ileft - 1] >= h){
            ileft--;
        }
        while(iright < r && a[iright + 1] >= h){
            iright++;
        }
        maxS = max(maxS, (long long)(iright - ileft +1)*h);
        if(ileft > l){
            if(iright < r){
                h = max(a[ileft - 1], a[iright + 1]);
            }
            else{
                h = a[ileft - 1];
            }
        }
        else{
            if(iright < r){
                h = a[iright + 1];
            }
            else{
                h = 0;
            }
        }
    }
    long long left = Hist(l, m);
    long long rigt = Hist(m+1, r);
    return max(maxS, max(left, rigt));
}

int main()
{
    int n;
    cin >> n;
    while(n!=0){
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        cout << Hist(1, n) << endl;
        cin >> n;
    }
    return 0;
}
