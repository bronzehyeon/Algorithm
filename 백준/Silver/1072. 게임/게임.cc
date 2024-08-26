#include <iostream>
using namespace std;


long long N, M;
long long Z;
int ans = -1;

void search(long long s, long long e) {
    long long m = (s + e) / 2;

    if (s > e) {
        return;
    }

    if ((M + m) * 100 / (N + m) != Z && (M + m - 1) * 100 / (N + m - 1) == Z) {
        ans = m;
        return;
    }

    if ((M + m) * 100 / (N + m) == Z) {
        search(m + 1, e);
    }
    else {
        search(s, m - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    Z = M * 100 / N;
    

    search(1, 1000000000);

    cout << ans;
}
