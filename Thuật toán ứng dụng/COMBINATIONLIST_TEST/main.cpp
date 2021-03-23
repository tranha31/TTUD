#include <iostream>
#include <stack>

using namespace std;

struct state{
    int i, j, old_L;
    state(int _i = 0, int _j = 0, int _L = 0):
    i(_i), j(_j), old_L(_L){}
};

int main(){
    int n, k , m;
    cin >> n >> k >> m;
    int x[n+1];
    stack<state> s;
    int L = 0;
    int dem = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            dem++;
            if(dem == k){
                for (int i = 1; i <= n; ++i)
                    cout << x[i] << " \n"[i == n];
            }
            s.pop();
            continue;
        }
        if(top.j > 0){
            L = top.old_L;
        }
        if(top.j > 1){
            s.pop();
        continue;
        }
        if(top.j == 1 || L+1 < m){
            x[top.i] = top.j;
            top.old_L = L;
            //L = top.j ? L+1 : 0;
            if(top.j == 1){
                L = 0;
            }
            else{
                L++;
            }
            s.push(state(top.i+1,0));
        }
        ++top.j;
    }
    if(dem < k){
        cout << -1;
    }
    return 0;
}
