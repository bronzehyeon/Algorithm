#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int T;
int h, w;
char arr[101][101];
bool visited[101][101];
int dxy[2][4] = { {1, -1, 0, 0}, {0, 0, 1, -1} };

void exploreEdge(queue<pair<int, int>>& q, set<int>& key, vector<pair<int, int>> lock[27], int i, int j, int& ans) {
    if (arr[i][j] == '.') {
        visited[i][j] = true;
        q.push({i, j});
    } else if (arr[i][j] == '$') {
        visited[i][j] = true;
        arr[i][j] = '.';
        ans++;
        q.push({i, j});
    } else if (arr[i][j] >= 'a' && arr[i][j] <= 'z') {
        visited[i][j] = true;
        int idx = arr[i][j] - 'a';
        key.insert(idx);
        arr[i][j] = '.';
        q.push({i, j});
        for (int k = 0; k < lock[idx].size(); k++) {
            int openX = lock[idx][k].first;
            int openY = lock[idx][k].second;
            visited[openX][openY] = true;
            q.push({openX, openY});
        }
    } else if (arr[i][j] >= 'A' && arr[i][j] <= 'Z') {
        int idx = arr[i][j] - 'A';
        if (key.find(idx) != key.end()) {
            visited[i][j] = true;
            arr[i][j] = '.';
            q.push({i, j});
        } else {
            lock[idx].push_back({i, j});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> h >> w;

        for (int i = 0; i < h; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < w; j++) {
                arr[i][j] = str[j];
            }
        }

        queue<pair<int, int>> q;
        set<int> key;
        memset(visited, false, sizeof(visited));

        string keys;
        cin >> keys;
        if (keys[0] != '0') {
            for (int i = 0; i < keys.length(); i++) {
                key.insert(keys[i] - 'a');
            }
        }

        vector<pair<int, int>> lock[27];
        int ans = 0;

        // 가장자리 탐색 (첫 열, 마지막 열, 첫 행, 마지막 행)
        for (int i = 0; i < h; i++) {
            exploreEdge(q, key, lock, i, 0, ans);          // 첫 번째 열
            exploreEdge(q, key, lock, i, w - 1, ans);      // 마지막 열
        }
        for (int i = 0; i < w; i++) {
            exploreEdge(q, key, lock, 0, i, ans);          // 첫 번째 행
            exploreEdge(q, key, lock, h - 1, i, ans);      // 마지막 행
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int m = 0; m < 4; m++) {
                int nx = x + dxy[0][m];
                int ny = y + dxy[1][m];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny]) {
                    continue;
                }

                if (arr[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else if (arr[nx][ny] == '$') {
                    arr[nx][ny] = '.';
                    visited[nx][ny] = true;
                    ans++;
                    q.push({nx, ny});
                } else if (arr[nx][ny] == '*') {
                    continue;
                } else if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
                    char findKey = arr[nx][ny];
                    visited[nx][ny] = true;
                    arr[nx][ny] = '.';
                    q.push({nx, ny});

                    int idx = findKey - 'a';
                    if (key.find(idx) == key.end()) {
                        key.insert(idx);
                        for (int i = 0; i < lock[idx].size(); i++) {
                            int openX = lock[idx][i].first;
                            int openY = lock[idx][i].second;
                            visited[openX][openY] = true;
                            q.push({openX, openY});
                        }
                    }
                } else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') {
                    int idx = arr[nx][ny] - 'A';
                    if (key.find(idx) != key.end()) {
                        visited[nx][ny] = true;
                        arr[nx][ny] = '.';
                        q.push({nx, ny});
                    } else {
                        lock[idx].push_back({nx, ny});
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
