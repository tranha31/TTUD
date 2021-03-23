#include <bits/stdc++.h>

using namespace std;
//using std::string;

const int N = 10005, Q = 10005;
int n, q;
vector<string> s1[N], s2[Q];
map<string, int> mp[N];
map<string, int> qp[Q];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //Nhap vb
    cin >> n;
    cin.ignore();
    string s;
    for(int i=1; i<=n; i++){
        cin >> s;
        //Tach vb
        string b = "";
        for(int j=0; j<s.size(); j++){
            if(s[j]==','){
                if(b != ""){
                    s1[i].push_back(b);
                }
                b = "";
            }
            else{
                b += s[j];
            }
            if(j == s.size()-1 && s[j] != ','){
                s1[i].push_back(b);
            }
        }
    }

    //Nhap tv
    cin >> q;
    cin.ignore();
    for(int i=1; i<=q; i++){
        cin >> s;
        //Tach tv
        string b = "";
        for(int j=0; j<s.size(); j++){
            if(s[j]==','){
                if(b != ""){
                    s2[i].push_back(b);
                }
                b = "";
            }
            else{
                b += s[j];
            }
            if(j == s.size()-1 && s[j] != ','){
                s2[i].push_back(b);
            }
        }

    }
    //Dem so lan xh cua moi ki tu trong vb
    for(int i=1; i<=n; i++){
        for(int j=0; j<s1[i].size(); j++){
            if(mp[i].find(s1[i].at(j)) == mp[i].end()){
                mp[i].insert(make_pair(s1[i].at(j), 1));
            }
            else{
                mp[i][s1[i].at(j)]++;
            }
        }
    }
    //Dem so lan xh cua moi ki tu trong tv
    map<string, int> df;
    for(int i=1; i<=q; i++){
        for(int j=0; j<s2[i].size(); j++){
            if(qp[i].find(s2[i].at(j)) == qp[i].end()){
                qp[i].insert(make_pair(s2[i].at(j), 1));
                df.insert(make_pair(s2[i].at(j), 0));
            }
            else{
                qp[i][s2[i].at(j)]++;
            }
        }
    }

    //Tim so lan xh max trong moi tv
    int max_x[n+1];
    for(int i=1; i<=n; i++){
        max_x[i] = INT_MIN;
        for(auto it : mp[i]){
            if(max_x[i] < it.second){
                max_x[i] = it.second;
            }
        }
    }
    //
    vector<pair<string, int>> t[q+1];

    for(int i=1; i<=q; i++){
        //map<string, int>::iterator it;
        for(auto it : qp[i]){
            t[i].push_back(make_pair(it.first, it.second));
        }
    }
    //so lan xh cua moi tu trong tung vb
    //map<string, int>::iterator it;
    for(auto it : df){
        for(int i=1; i<=n; i++){
            if(mp[i].find(it.first) != mp[i].end()){
                df[it.first]++;
            }
        }
    }

    //Begin
    int KQ[q+1];
    for(int i=1; i<=q; i++){
        int index = 1;
        int myindex;
        float max_s = -FLT_MAX;
        for(int j=1; j<=n; j++){
            map<string, int>::iterator it;
            float score = 0;
            for(int k=0; k<t[i].size(); k++){
                int ft = 0;
                it = mp[j].find(t[i].at(k).first);
                //cout << j << "\n" << "-------------" << endl;
                if(it != mp[j].end()){
                    ft = it->second;
                    int df1 = df[it->first];

                    //cout << it->first << ":";
                    //cout << "df" << df1 << " ";
                    float TF = 0.5+0.5*(float)ft/(float)max_x[j];
                    //cout << "ft" << ft << " ";
                    //cout << "max" << max_x[j] << " ";
                    //cout << "TF" << TF << " ";
                    float IDF = (float)(log2((float)n/(float)df1));
                    //cout << "IDF" << IDF << endl;
                    score += TF*IDF*(float)t[i].at(k).second;
                    //cout << score << " ";
                }
                //cout << endl;
            }
            //cout << score << endl;
            //cout << endl;
            if(score > max_s){
                max_s = score;
                myindex = index;
            }
            ++index;
        }
        KQ[i] = myindex;
    }
    for(int i=1; i<=q; i++){
        cout << KQ[i] << endl;
    }
    return 0;
}
