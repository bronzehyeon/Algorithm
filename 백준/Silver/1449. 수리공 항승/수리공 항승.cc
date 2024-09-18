#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N, L;

vector<float> fix;

vector<int> v;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int ans = 1;
    fix.push_back(v[0] + L - 0.5);

    for (int i = 1; i < N; i++) {
        if (v[i] + 0.5 > fix[ans - 1]) {
            ans++;
            fix.push_back(v[i] + L - 0.5);
        }
    }

    cout << ans;
}