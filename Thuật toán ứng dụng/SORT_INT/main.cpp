#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
int main()
{
    int n;
    vector<int> a;
    int x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        a.push_back(x);
    }
    PQ p(a.begin(), a.end());
    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }
    return 0;
}
