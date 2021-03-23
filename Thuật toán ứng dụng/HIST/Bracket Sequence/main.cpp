#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    string a;
    stack<char> sk;
    stack<int> vt;
    vector<tuple<int, int, int>> kq;
    cin >> a;
    bool OK = false;
    int dem = 0;
    int max_s = 0;
    int begin_s = INT_MAX, end_s = -1;
    for(int i=0; i<a.size(); i++){
        if(a[i] == '(' || a[i] == '['){
            sk.push(a[i]);
            vt.push(i);
        }
        else if(a[i] == ')'){
            if(!vt.empty()){
                if(a[vt.top()] == '('){

                    OK = true;
                    if(begin_s > vt.top()){
                        begin_s = vt.top();
                    }
                    end_s = i;
                    sk.pop();
                    vt.pop();
                }
                else{
                    kq.push_back(make_tuple(begin_s, end_s, dem));
                    dem = 0;
                    begin_s = INT_MAX;
                    while(!vt.empty()){
                        vt.pop();
                        sk.pop();
                    }
                }
            }
            else{
                kq.push_back(make_tuple(begin_s, end_s, dem));
                dem = 0;
                begin_s = INT_MAX;
            }
        }
        else if(a[i] == ']'){
            if(!vt.empty()){
                if(a[vt.top()] == '['){
                    OK = true;
                    if(begin_s > vt.top()){
                        begin_s = vt.top();
                    }
                    end_s = i;
                    sk.pop();
                    vt.pop();
                    dem ++;
                }
                else{
                    kq.push_back(make_tuple(begin_s, end_s, dem));
                    dem = 0;
                    begin_s = INT_MAX;
                    while(!vt.empty()){
                        vt.pop();
                        sk.pop();
                    }
                }
            }
            else{
                kq.push_back(make_tuple(begin_s, end_s, dem));
                dem = 0;
                begin_s = INT_MAX;
            }
        }
    }
    kq.push_back(make_tuple(begin_s, end_s, dem));
    int dd;
    for(int i=0; i<kq.size(); i++){
        if(get<2>(kq.at(i)) > max_s){
            max_s = get<2>(kq.at(i));
            dd = i;
        }
    }
    int k;
    int kmax = 0;
    if(max_s == 0){
        for(int i=0; i<kq.size(); i++){
            k = get<1>(kq.at(i)) - get<0>(kq.at(i));
            if(k > kmax){
                kmax = k;
                dd = i;
            }
        }
    }
    cout << max_s << endl;
    if(OK){
        for(int i=get<0>(kq.at(dd)); i<=get<1>(kq.at(dd)); i++){
            cout << a[i];
        }
    }

    return 0;
}
