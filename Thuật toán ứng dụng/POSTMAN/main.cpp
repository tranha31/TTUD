#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> duong;
vector<pair<int, int>> am;
int n, k;

long long KC(vector<pair<int, int>> a){
    long long dem = 0;
    while(!a.empty()){
        while(a.at(a.size()-1).second > 0){
            int du = 0;
            if(a.at(a.size()-1).second > k){
                a.at(a.size()-1).second -= k;
                dem += 2*a.at(a.size()-1).first;
            }
            else{
                du = k - a.at(a.size()-1).second;
                //a.at(a.size()-1).second = 0;
                dem += 2*a.at(a.size()-1).first;
                a.pop_back();
                if(a.size() >= 1){
                    for(int i=a.size()-1; i>=0; i--){
                        if(du == 0){
                            break;
                        }
                        if(a.at(i).second > du){
                            a.at(i).second -= du;
                            du = 0;
                            break;
                        }
                        else{
                            du -= a.at(i).second;
                            a.at(i).second = 0;
                            a.pop_back();
                        }
                    }
                }
                if(a.empty()){
                    break;
                }
            }
        }
    }
    return dem;
}
int main()
{
    cin >> n;
    cin >> k;
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a;
        cin >> b;
        if(a > 0){
            duong.push_back(make_pair(a, b));
        }
        else{
            am.push_back(make_pair(a, b));
        }
    }
    sort(duong.begin(), duong.end());
    sort(am.begin(), am.end(), greater<pair<int, int>>());
    long long sum = 0;
    if(k == 1){
        long long m = 0;
        for(int i=0; i<duong.size(); i++){
            m = (long long)duong.at(i).first * duong.at(i).second;
            sum += m*2;
        }
        for(int i=0; i<am.size(); i++){
            m = (long long)am.at(i).first * am.at(i).second;
            sum -= m*2;
        }
    }
    else{
        sum += KC(duong);
        sum -= KC(am);
    }
    cout << sum << endl;
    return 0;
}
