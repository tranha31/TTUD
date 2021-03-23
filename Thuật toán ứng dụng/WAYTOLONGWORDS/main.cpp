#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string vb;
    std::string tmp;
    vector<string> a;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> vb;
        if(vb.length() <= 10)
        {
            a.push_back(vb);
        }
        else
        {
            tmp = std::to_string(vb.length()-2);
            vb = vb[0] + tmp + vb[vb.length()-1];
            a.push_back(vb);
        }

    }
    for(int i=0; i<n; i++)
    {
        cout << a.at(i) << endl;
    }
    return 0;
}
