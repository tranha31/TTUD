#include <bits/stdc++.h>
using namespace std;

int Try(string str)
{
    int n = str.length();
    map< int, int > mp;
    mp[0] = 1;
    int zc = 0, oc = 0;
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == '0'){
           zc++;
        }
        else {
            oc++;
        }
        int tmp = zc - oc;
        res = res + mp[tmp];
        mp[tmp]++;
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << Try(s) << endl;
    return 0;
}
