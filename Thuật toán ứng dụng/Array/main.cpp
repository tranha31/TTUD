#include <iostream>
#include <vector>

using namespace std;
vector<int> nhom1;
vector<int> nhom2;
vector<int> nhom3;

int main()
{
    int x;
    int am = 0;
    int duong = 0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x == 0){
            nhom3.push_back(0);
        }
        else if(x > 0){
            nhom2.push_back(x);
            duong++;
        }
        else{
            nhom1.push_back(x);
            am++;
        }
    }
    if(duong == 0 && am != 0){
        if(am%2 == 0){
            nhom2.push_back(nhom1.at(nhom1.size()-1));
            nhom2.push_back(nhom1.at(nhom1.size()-2));
            nhom3.push_back(nhom1.at(nhom1.size()-3));
            nhom1.pop_back();
            nhom1.pop_back();
            nhom1.pop_back();
        }
        else{
            nhom2.push_back(nhom1.at(nhom1.size()-1));
            nhom2.push_back(nhom1.at(nhom1.size()-2));
            nhom1.pop_back();
            nhom1.pop_back();
        }
    }
    else if(duong !=0 && am != 0){
        if(am%2 == 0){
            nhom3.push_back(nhom1.at(nhom1.size()-1));
            nhom1.pop_back();
        }
    }
    cout << nhom1.size() << " ";
    for(int i=0; i<nhom1.size(); i++){
        cout << nhom1.at(i) << " ";
    }
    cout << endl;
    cout << nhom2.size() << " ";
    for(int i=0; i<nhom2.size(); i++){
        cout << nhom2.at(i) << " ";
    }
    cout << endl;
    cout << nhom3.size() << " ";
    for(int i=0; i<nhom3.size(); i++){
        cout << nhom3.at(i) << " ";
    }
    return 0;
}
