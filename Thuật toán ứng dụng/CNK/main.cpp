#include <bits/stdc++.h>
#include <vector>
#include <tuple>

const int N = 100001;
using namespace std;

long long factorialNumInverse[N + 1];

long long naturalNumInverse[N + 1];

long long fact[N + 1];

vector<tuple<long long, long long, long long>> A;

void InverseofNumber(long long p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}

void InverseofFactorial(long long p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(long long p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

int Binomial(long long N, long long R, long long p)
{
    int ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

int main()
{
    long long n, r, p;
    int k;
    cin >> k;
    for(int i=1; i<=k; i++){
        cin >> n >> r >> p;
        A.push_back(make_tuple(n, r, p));
    }
    for(int i=0; i<A.size(); i++){
        InverseofNumber(get<2>(A.at(i)));
        InverseofFactorial(get<2>(A.at(i)));
        factorial(get<2>(A.at(i)));
        cout << Binomial(get<0>(A.at(i)), get<1>(A.at(i)), get<2>(A.at(i))) << endl;
    }
    /*InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);

    // 1st query
    ll N = 7;
    ll R = 3;
    cout << Binomial(N, R, p) << endl;

    // 2nd query
    N = 5;
    R = 2;
    cout << Binomial(N, R, p) << endl;
*/
    return 0;
}
