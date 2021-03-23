#include <iostream>
#include <queue>

using namespace std;
typedef struct{
    int x, y, step;
}S;
bool visited[901][901] = {false};
int findMin(int a, int b){
    if(a > b){
        return b;
    }
    else return a;
}
int waterjub(int a, int b, int c){
    queue<S> q;
    q.push({0, 0 , 0});
    visited[0][0] = true;
    S s;
    while(!q.empty()){
        s = q.front();
        if(s.x == c || s.y == c){
            return s.step;
        }
        if(s.x < a){
            if(!visited[a][s.y]){
                visited[a][s.y] = true;
                q.push({a, s.y, s.step+1});
            }
            if(s.y > 0){
                int min_x = findMin(a-s.x, s.y);
                if(!visited[s.x+min_x][s.y-min_x]){
                    visited[s.x+min_x][s.y-min_x];
                    q.push({s.x+min_x, s.y-min_x, s.step+1});
                }
            }
        }
        if(s.y < b){
            if(!visited[s.x][b]){
                visited[s.x][b] = true;
                q.push({s.x, b, s.step+1});
            }
            if(s.x > 0){
                int min_x = findMin(s.x, b-s.y);
                if(!visited[s.x-min_x][s.y+min_x]){
                    visited[s.x-min_x][s.y+min_x] = true;
                    q.push({s.x-min_x, s.y+min_x, s.step+1});
                }
            }
        }
        if(s.x > 0){
            if(!visited[0][s.y]){
                visited[0][s.y] = true;
                q.push({0, s.y, s.step+1});
            }
        }
        if(s.y > 0){
            if(!visited[s.x][0]){
                visited[s.x][0] = true;
                q.push({s.x, 0, s.step+1});
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << waterjub(a, b, c);
    return 0;
}
