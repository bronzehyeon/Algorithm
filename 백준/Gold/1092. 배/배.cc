#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> limit;
    vector<int> weight;

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        limit.push_back(tmp);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        weight.push_back(tmp);
    }

    sort(limit.begin(), limit.end(), greater<int>());
    sort(weight.begin(), weight.end(), greater<int>());

    int answer = 0;
    int count = 0;
    
    if (limit[0] < weight[0]) {
        cout << -1;
    }
    else {
        while (count < M) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (limit[i] >= weight[j]) {
                        weight[j] = limit[0] + 1;
                        count++;
                        break;
                    }
                }
                if (count >= M) {
                    break;
                }
            }
            answer++;
        }
        cout << answer;
    }

    return 0;
}

