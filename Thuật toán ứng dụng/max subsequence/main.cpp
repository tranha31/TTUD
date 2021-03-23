#include <iostream>

using namespace std;

const int N = 1000007;
int a[N], mem[N];
int n;
bool comp[N];

int max_sum(int i){
    if(i == 0){
        return a[i];
    }
    if(comp[i]){
        return mem[i];
    }
    int res = max(a[i], a[i] + max_sum(i-1));
    mem[i] = res;
    comp[i] = true;
    return res;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        comp[i] = false;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, max_sum(i));
    }
    cout << ans;
    return 0;
}
