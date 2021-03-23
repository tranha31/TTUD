#include<bits/stdc++.h>
using namespace std;

const int N = 25;
const int INF = 1000000000;


int n, k;
int c[N][N];

bool visited[N];
int curLength = 0;
int ans = INF;
int nPassengerInBus = 0;

int minCost = INF;

void backtrack(int nVisited, int curPassenger) {

        if (nVisited == 2 * n + 1) {
                ans = min(ans, curLength + c[curPassenger][0]);
                return;
        }

        // don khach
        if (nPassengerInBus < k) {
                for (int i = 1; i <= n; i++) {
                        if (visited[i])
                                continue;

                        int bound = curLength + c[curPassenger][i];
                        // nVisited + 1 dinh -> da di qua nVisited canh
                        bound += (2 * n + 1 - nVisited) * minCost;
                        if (bound >= ans) {
                                continue;
                        }

                        visited[i] = true;
                        curLength = curLength + c[curPassenger][i];
                        nPassengerInBus++;
                        backtrack(nVisited + 1, i);
                        nPassengerInBus--;
                        curLength = curLength - c[curPassenger][i];
                        visited[i] = false;
                }
        }

        // tra khach

        for (int i = n + 1; i <= 2 * n; i++) {
                if (visited[i])
                        continue;

                if (visited[i - n] == false)
                        continue;

                int bound = curLength + c[curPassenger][i];
                // nVisited + 1 dinh -> da di qua nVisited canh
                bound += (2 * n + 1 - nVisited) * minCost;
                if (bound >= ans) {
                        continue;
                }

                visited[i] = true;
                curLength = curLength + c[curPassenger][i];
                nPassengerInBus--;
                backtrack(nVisited + 1, i);
                nPassengerInBus++;
                curLength = curLength - c[curPassenger][i];
                visited[i] = false;
        }

}


int main() {

        cin >> n >> k;

        for (int i = 0; i <= 2 * n; i++) {
                for (int j = 0; j <= 2 * n; j++) {
                        cin >> c[i][j];
                        if (i != j)
                                minCost = min(minCost, c[i][j]);
                }
        }


        visited[0] = true;

        backtrack(1, 0);

        cout << ans << endl;

        return 0;
}
