#include <bits/stdc++.h>

using namespace std;
const int N = 2000005;
int n;
int mem[N];

vector<pair<int, int>> a;

int dp(int i){
    //cout << "111113" << endl;
    if(mem[i] != -1){
        return mem[i];
    }
    int tmp = a.at(i).second - a.at(i).first;
    int res = tmp;
    for(int j=0; j<i; j++){
        //if(j != i){
            if(a.at(j).second < a.at(i).first){

                res = max(res, tmp + dp(j));
            }
        //}
    }
    mem[i] = res;
    return res;
}

int main()
{
    scanf("%d", &n);
    int x, y;
    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end(), [](auto x, auto y){ return x.second < y.second;});
    memset(mem, -1, sizeof(mem));
    int ans = 0;
    mem[0] = a.at(0).second - a.at(0).first;
    for(int i=0; i<n; i++){
        ans = max(ans, dp(i));
    }
    /*for(int i=0; i<n; i++){
        cout << mem[i] << endl;
    }*/
    cout << ans;
    return 0;

}
