#include <iostream>

using namespace std;

void solve(int N, int L) {
    if (L > 100) {
        cout << -1;
        return;
    }
    if (L % 2 == 1) {
        if (N / L - L / 2 < 0) {
            cout << -1;
            return;
        }
        if (N / L * L == N) {
            //cout << L;
            for (int i = 0; i < L; i++) {
                cout << N / L - L / 2 + i << " ";
            }
        }
        else {
            solve(N, L + 1);
        }
    }
    else {
        if (N / L - L / 2 < -1) {
            cout << -1;
            return;
        }
        if (N / L * L + L / 2 == N) {
            //cout << L;
            for (int i = 1; i <= L; i++) {
                cout << N / L - L / 2 + i << " ";
            }
        }
        else {
            solve(N, L + 1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    cin >> N >> L;

    solve(N, L);
    
    
}

