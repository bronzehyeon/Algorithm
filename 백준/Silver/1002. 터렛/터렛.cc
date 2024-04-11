#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[501][501];
int sum[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sum[0] = 0;
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int distance_pow = pow((x1 - x2), 2) + pow((y1 - y2), 2);
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                cout << -1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (distance_pow > pow((r1 + r2), 2) || distance_pow < pow((r1 - r2), 2)) {
            cout << 0 << '\n';
        }
        else if (distance_pow == pow((r1 + r2), 2) || distance_pow == pow((r1 - r2), 2)) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }
    return 0;
}