#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void binary_search(int s, int e, int t) {
    if (s > e) {
        cout << 0 << '\n';
        return;
    }
    if (v[(s + e) / 2] == t) {
        cout << 1 << '\n';
    }
    else if (v[(s + e) / 2 ] > t) {
        binary_search(s, (s + e) / 2 - 1, t);
    }
    else if (v[(s + e) / 2] < t) {
        binary_search((s + e) / 2 + 1, e, t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;

        binary_search(0, N - 1, tmp);
        
    }
    

}