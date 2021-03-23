#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10005;
int a[N], mem[N];
int n;

int lt(int i){
    if(mem[i] != -1){
        return mem[i];
    }
    int res = 1;
    for(int j=0; j<i; j++){
        if(a[j] < a[i]){
            res = max(res, 1 + lt(j));
        }
    }
    mem[i] = res;
    return res;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mem[i] = -1;
    }
    int max_s = 0;
    for(int i=0; i<n; i++){
        max_s = max(max_s, lt(i));
    }
    cout << max_s;
    return 0;
}
