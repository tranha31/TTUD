#include <iostream>
#include <stack>

using namespace std;
int n;
int a[30];

struct state{
    int i, j;
    state(int _i = 0, int _j = 0):
    i(_i), j(_j){}
};

/*void Try(int k){
    if(k > n){
        for(int i=1; i<=n; i++){
            cout << a[i];
        }
        cout << endl;
    }
    else{
        for(int i=0; i<=1; i++){
            a[k] = i;
            Try(k+1);
        }
    }
}
*/
int main()
{
    cin >> n;
    int x[n+1];
    stack<state> s;
    s.push(state(1, 0));
    while(!s.empty()){
        state &top = s.top();
        if(top.i > n){
            for(int i=1; i<=n; i++){
                cout << x[i];
            }
            cout << endl;
            s.pop();
            continue;
        }
        if(top.j > 1){
            s.pop();
            continue;
        }
        x[top.i] = top.j;
        s.push(state(top.i+1, 0));
        ++top.j;
    }
    //Try(1);
    return 0;
}
