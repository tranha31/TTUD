#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c;
    //typename map<T, double>::iterator i;
    //typename map<T, double>::iterator j;
    for(const auto &i : a){
        if(b.find(i.first) != b.end()){
            c.insert(make_pair(i.first, max(i.second, b.find(i.first)->second)));
        }
        else{
            c.insert({i.first, i.second});
        }
    }
    for(const auto &j : b){
        if(c.find(j.first) == c.end()){
            c.insert({j.first, j.second});
        }
    }

    //sort(c.begin(), c.end(), [] (const map<T, double> &x, const map<T, double> &y){return x->first < y->first;});
    return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c;
    //typename map<T, double>::iterator i;
    //typename map<T, double>::iterator j;
    for(const auto &i : a){
        if(b.find(i.first) != b.end()){
            c.insert(make_pair(i.first, min(i.second, b.find(i.first)->second)));
        }
        else{
            c.insert({i.first, 0});
        }
    }
    for(const auto &j : b){
        if(c.find(j.first) == c.end()){
            c.insert({j.first, 0});
        }
    }
    //sort(c.begin(), c.end(), [] (const map<T, double> &x, const map<T, double> &y){return x.first < y.first;});
    return c;
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
