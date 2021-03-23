#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n;
    while(n--){
        cin >> m >> k;
        long long a[m];
        long long maxx = 0;
        for(int i=0; i<m; i++){
            cin >> a[i];
            if(a[i] > maxx){
                maxx = a[i];
            }
        }
        //sort(a, a+m);
        long long ans = 0;
        long long r = maxx, l = m*maxx;
        while(r <= l){
            //cout << 1111 << endl;
            long long mid = (l+r)/2;
            //cout << l << " " << mid << " " << r << endl;
            int c = 0;
            long long s = 0;
            for(int i=m-1; i>=0; i--){
                //cout << 222 << endl;
                if(s + a[i] > mid){
                    c++;
                    s = 0;
                }
                s += a[i];
            }
            c++;
            //cout << 333 << endl;
            if(c <= k){
                ans = mid;
                l = mid-1;
            }
            else{
               // ans = max(ans, mid);
                r = mid+1;
            }
        }
        long long s = 0;
        vector<int> dd;
        int c = 0;
        for(int i=m-1; i>=0; i--){
            if(s+a[i] >= ans){
                c++;
                dd.push_back(i-1);
                s = 0;
                /*if(c < k){
                    dd.push_back(i+1);
                    s = 0;
                }*/
            }
            else{
                s += a[i];
            }
        }
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
            for(int j=0; j<dd.size(); j++){
                if(i == dd.at(j)){
                    cout << " / ";
                }
            }
        }
        cout << endl;
        //cout << ans << endl;
    }
    return 0;
}
