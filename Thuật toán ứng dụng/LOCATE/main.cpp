#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;
int l, c;
vector<pair<int, int>> a, b;
int d[2*1010][2*1010];

int main()
{
    int T;
    cin >> T;
    while(T!=0){
        int maxS = 0;
        cin >> l >> c;
        int x;
        for(int i=0; i<l; i++){
            for(int j=0; j<c; j++){
                cin >> x;
                if(x == 1){
                    a.push_back(make_pair(i, j));
                }
            }
        }
         for(int i=0; i<l; i++){
            for(int j=0; j<c; j++){
                cin >> x;
                if(x == 1){
                    b.push_back(make_pair(i, j));
                }
            }
        }
        int u, v;
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<b.size(); j++){
                u = a[i].first - b[j].first;
                v = a[i].second - b[j].second;
                maxS = max(maxS, ++d[u + 1010][v + 1010]);
            }
        }
        cout << maxS << endl;
        a.clear(), b.clear();
        memset(d, 0, sizeof(d));
        T--;
    }
    return 0;
}
