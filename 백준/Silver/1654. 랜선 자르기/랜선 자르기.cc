#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
vector<int> v;
int answer = 0;

void solve(long s, long e) {
    if (s > e)
        return;
    long sum = 0;
    long cut = (s + e) / 2;
    if (cut == 0)
        cut = 1;
    for (int i = 0; i < K; i++) {
        sum += v[i] / cut;
    }
    if (sum >= N) {
        if (cut > answer)
            answer = cut;
        solve(cut + 1, e);
    }
    else {
        solve(s, cut - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> K >> N;

    long maxLen = 0;

    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        if (maxLen < tmp)
            maxLen = tmp;
    }

    solve(0, maxLen);

    cout << answer;

}