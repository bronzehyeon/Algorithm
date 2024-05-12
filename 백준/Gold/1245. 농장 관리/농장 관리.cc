#include <iostream>
#include <queue>

using namespace std;

int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int arr[100][70];
bool visited[100][70];
int ans;
bool isHighest = true;
int N, M;

void BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    visited[i][j] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (arr[i][j] < arr[nx][ny]) isHighest = false;

            if (visited[nx][ny] || arr[i][j] != arr[nx][ny]) continue;

            q.push({ nx,ny });
            visited[nx][ny] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                isHighest = true;
                BFS(i, j);
                if (isHighest) ans++;
            }
        }
    }
    
    cout << ans;

}
