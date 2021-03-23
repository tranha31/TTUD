#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
vector<int> so1;
vector<int> so2;
vector<int> sum;

inline void Doi(string a, string b)
{
    int n1 = a.length();
    int n2 = b.length();
    if(n1 > n2)
    {
        for(int i=n1-1; i>=0; i--)
        {
            so1.push_back(a[i] - '0');
        }
        for(int i=n2-1; i>=0; i--)
        {
            so2.push_back(b[i] - '0');
        }
    }
    else
    {
        for(int i=n2-1; i>=0; i--)
        {
            so1.push_back(b[i] - '0');
        }
        for(int i=n1-1; i>=0; i--)
        {
            so2.push_back(a[i] - '0');
        }
    }
}
inline void TinhTong()
{
    int nho = 0;
    int tmp;
    for(int i=0; i<so2.size(); i++)
    {
        tmp = so2.at(i) + so1.at(i) + nho;
        if(tmp >= 10)
        {
            nho = 1;
            sum.push_back(tmp-10);
        }
        else
        {
            nho = 0;
            sum.push_back(tmp);
        }
    }
    for(int i=so2.size(); i<so1.size(); i++)
    {
        tmp = so1.at(i) + nho;
        if(tmp >= 10)
        {
            nho = 1;
            sum.push_back(tmp-10);
        }
        else
        {
            nho = 0;
            sum.push_back(tmp);
        }
    }
    if(nho == 1)
    {
        sum.push_back(1);
    }
}
int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    Doi(a, b);
    TinhTong();
    for(int i=sum.size()-1; i>=0; i--)
    {
        cout << sum.at(i);
    }

    return 0;
}
