#include <iostream>
using namespace std;

int N, M;

int arr[1000][1000];

bool visited[1000][1000];
bool rec[1000][1000];

int dir[4][2] = { {1, 0},{-1,0},{0,1},{0,-1} };

int ans = 0;

void dfs(int x, int y) {
    //cout << x << " " << y << '\n';
    int nextX = x + dir[arr[x][y]][0];
    int nextY = y + dir[arr[x][y]][1];

    visited[x][y] = true;
    rec[x][y] = true;

    if (rec[nextX][nextY]) {
        visited[nextX][nextY] = true;
        ans++;
        rec[x][y] = false;
        return;
    }

    if (visited[nextX][nextY]) {
        rec[x][y] = false;
        return;
    }

    dfs(nextX, nextY);
    rec[x][y] = false;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'D') {
                arr[i][j] = 0;
            }
            if (c == 'U') {
                arr[i][j] = 1;
            }
            if (c == 'R') {
                arr[i][j] = 2;
            }
            if (c == 'L') {
                arr[i][j] = 3;
            }
            
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    cout << ans;

}