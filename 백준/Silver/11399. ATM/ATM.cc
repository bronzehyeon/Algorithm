#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            answer += v[j];
        }
    }

    cout << answer;

}

    