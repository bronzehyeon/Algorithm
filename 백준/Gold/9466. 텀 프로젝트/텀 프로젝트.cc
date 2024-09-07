#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;

int N;

int arr[100001];

bool visited[100001];

int rec[100001];

int ans;

void dfs(int x, int cnt) {
    //cout << x << " " << " " << cnt << '\n';
    visited[x] = true;
    rec[x] = cnt;

    int next = arr[x];

    if (rec[next]) {
        visited[next] = true;
        ans -= (cnt - rec[next] + 1);
        rec[x] = 0;
        return;
    }

    if (!visited[next]) {
        dfs(next, cnt + 1);
    }

    rec[x] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        memset(visited, false, sizeof(visited));
        memset(rec, 0, sizeof(rec));
        ans = N;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i, 1);
            }
        }

        cout << ans << '\n';
    }
}
