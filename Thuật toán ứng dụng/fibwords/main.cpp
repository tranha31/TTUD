#include <iostream>
#include <string>
#include <string.h>

using namespace std;
string mem[1000];

string fib(int n){
    if(n <= 0){
        return "0";
    }
    if(n == 1){
        return "1";
    }
    if(mem[n] != ""){

        return mem[n];
    }
    string res = fib(n-1) + fib(n-2);
    mem[n] = res;
    return res;
}

long long countFreq(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;

    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;
        if (j == M)
        {
           res++;
           j = 0;
        }
    }
    return res;
}

int main()
{
    long long kq[1000];
    int T;
    cin >> T;
    for(int k=1; k<=T; k++){
        int n;
        cin >> n;
        string s;
        cin >> s;

        for(int i=0; i<n; i++){
            mem[i] = "";
        }
        fib(n);
        kq[k] = countFreq(s, mem[n]);
        for(int i=0; i<n; i++){
            mem[i] = "";
        }
        //cout << "Case " << k << ": " << countFreq(s, mem[n]) << endl;
    }
    for(int k=1; k<=T; k++){
        cout << "Case " << k << ": " << kq[k] << endl;
    }
    return 0;
}
