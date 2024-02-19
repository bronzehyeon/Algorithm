#include <iostream>
using namespace std;

int num[100];
int op[4];
int minResult = 1000000000;
int maxResult = -1000000000;

void solve(int result, int idx, int count) {

    if (idx == count) {
        if (result > maxResult)
            maxResult = result;
        if (result < minResult)
            minResult = result;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            switch (i) {
            case 0:
                op[i]--;
                solve(result + num[idx], idx + 1, count);
                op[i]++;
                break;
            case 1:
                op[i]--;
                solve(result - num[idx], idx + 1, count);
                op[i]++;
                break;
            case 2:
                op[i]--;
                solve(result * num[idx], idx + 1, count);
                op[i]++;
                break;
            case 3:
                op[i]--;
                solve(result / num[idx], idx + 1, count);
                op[i]++;
                break;
            }
        }
    }

}

int main() {

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    solve(num[0], 1, N);

    cout << maxResult << '\n';
    cout << minResult << '\n';
     
}