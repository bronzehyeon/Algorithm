#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H;
int arr[100][100][100];
int ans[100][100][100];
bool visited[100][100][100];
queue<pair<pair<pair<int, int>, int>, int>> q;

void bfs() {
	while (!q.empty()) {
		int a = q.front().first.first.first;
		int b = q.front().first.first.second;
		int c = q.front().first.second;
		int cnt = q.front().second;
		ans[a][b][c] = cnt;
		q.pop();
		 
		if (a + 1 < M && !visited[a + 1][b][c] && arr[a + 1][b][c] == 0) {
			arr[a + 1][b][c] = 1;
			visited[a + 1][b][c] = true;
			q.push(make_pair(make_pair(make_pair(a + 1, b), c), cnt + 1));
		}
		if (b + 1 < N && !visited[a][b + 1][c] && arr[a][b + 1][c] == 0) {
			arr[a][b + 1][c] = 1;
			visited[a][b + 1][c] = true;
			q.push(make_pair(make_pair(make_pair(a, b + 1), c), cnt + 1));
		}
		if (c + 1 < H && !visited[a][b][c + 1] && arr[a][b][c + 1] == 0) {
			arr[a][b][c + 1] = 1;
			visited[a][b][c + 1] = true;
			q.push(make_pair(make_pair(make_pair(a, b), c + 1), cnt + 1));
		}
		if (a - 1 >= 0 && !visited[a - 1][b][c] && arr[a - 1][b][c] == 0) {
			arr[a - 1][b][c] = 1;
			visited[a - 1][b][c] = true;
			q.push(make_pair(make_pair(make_pair(a - 1, b), c), cnt + 1));
		}
		if (b - 1 >= 0 && !visited[a][b - 1][c] && arr[a][b - 1][c] == 0) {
			arr[a][b - 1][c] = 1;
			visited[a][b - 1][c] = true;
			q.push(make_pair(make_pair(make_pair(a, b - 1), c), cnt + 1));
		}
		if (c - 1 >= 0 && !visited[a][b][c - 1] && arr[a][b][c - 1] == 0) {
			arr[a][b][c - 1] = 1;
			visited[a][b][c - 1] = true;
			q.push(make_pair(make_pair(make_pair(a, b), c - 1), cnt + 1));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	for (int h = 0; h < H; h++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				cin >> arr[i][j][h];

				if (arr[i][j][h] == 1) {
					q.push(make_pair(make_pair(make_pair(i, j), h), 0));
				}
			}
		}
	}

	bfs();

	int cnt = 0;

	for (int h = 0; h < H; h++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				if (arr[i][j][h] == 0) {
					cout << -1;
					return 0;
				}
				if (ans[i][j][h] > cnt) {
					cnt = ans[i][j][h];
				}
			}
		}
	}
	cout << cnt;
}