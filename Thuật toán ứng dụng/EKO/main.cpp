#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const unsigned int N = 10000004;
unsigned int a[N], b[N];
unsigned int n, m, h;

unsigned long long Count(unsigned int h){
    unsigned long long sum = 0;
    for(unsigned int i=n-1; i>=0; i--){
        if(a[i] > h){
            sum += a[i] - h;
        }
        else{
            break;
        }
    }
    return sum;
}

void Find(unsigned int l, unsigned int r){
    if(l >= r-1){
        printf("%d", l);
        //cout << h;
        return;
    }

    h = (l+r)/2;
    unsigned long long ab = Count(h);
    if(ab > m){
        l = h;
    }
    else if (ab < m){
        r = h;
    }
    else{
        printf("%d", h);
        //cout << h;
        return;
    }
    Find(l, r);
}

int main()
{
    //cin >> n >> m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(unsigned int i=0; i<n; i++){
        scanf("%d", &a[i]);
        //cin >> a[i];
    }
    sort(a, a+n);
    Find(a[0], a[n-1]);
    return 0;
}
