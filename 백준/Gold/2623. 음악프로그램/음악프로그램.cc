#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int before[1001];

vector<int> v[1001];
vector<int> ans;

queue<int> q;

int main() {
    cin >> N >> M;

    while (M--) {
        int K;
        cin >> K;

        int a, b;

        cin >> a;

        for (int i = 0; i < K - 1; i++) {
            cin >> b;
            v[a].push_back(b);
            before[b]++;
            a = b;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (before[i] == 0) {
            q.push(i);
        }
    }

    
    while (!q.empty()) {
        int singer = q.front();
        q.pop();
        ans.push_back(singer);

        for (int i = 0; i < v[singer].size(); i++) {
            int next = v[singer][i];
            before[next]--;
            if (before[next] == 0) {
                q.push(next);
            }
        }
    }
    
    if(ans.size() != N) {
        cout << 0 << '\n';
        return 0;
    }
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}
