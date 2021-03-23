#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;
int n, a[N], h[N], ma[N];
vector<int> trace;

int main()
{
    cin >> n;
    h[0] = -INT_MAX;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    h[1] = a[1];
    h[2] = a[2];
    ma[1] = a[1];
    ma[2] = max(a[1], a[2]);
    ans = max(ans, ma[2]);
    for(int i=3; i<=n; i++){
        h[i] = max(a[i], max(ma[i-2], ma[i-2]+a[i]));
        ma[i] = max(ma[i-1], h[i]);
        ans = max(ans, h[i]);
    }
    int tmp = ans;
    for(int i=n; i>0; i--){
        if(tmp == h[i]){
            for(int j=i; j>0; j--){
                if(h[j] != h[j-1]){
                    //cout << j << endl;
                    if(h[j] == h[j+1] && j-1 == 1){
                        //cout << j << endl;
                        trace.push_back(j+1);
                        tmp -= a[j+1];
                        //cout << tmp << endl;
                    }
                    else{
                        trace.push_back(j);
                        tmp -= a[j];
                        //cout << tmp << endl;
                    }
                    i = j-1;
                    break;
                }
            }
        }
    }
    /*for(int i=1; i<=n; i++){
        cout << h[i] << " ";
    }
    cout << endl;*/
    cout << ans << endl;
    cout << trace.size() << endl;
    for(int i=trace.size()-1; i>=0; i--){
        cout << trace.at(i) << " ";
    }
    return 0;
}
