#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[1000][1000][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = -1;


int bfs() {
	queue<pair<pair<int, int>, bool>> q;
	q.push({ {0,0}, false });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool crush = q.front().second;
		q.pop();


		if (x == N - 1 && y == M - 1) {
			return arr[N-1][M-1][crush] + 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			else {
				if (arr[nx][ny][0] == 0) {
					if (crush && arr[nx][ny][crush]) {
						continue;
					}
					else {
						arr[nx][ny][crush] = arr[x][y][crush] + 1;
						q.push({ { nx, ny }, crush });
					}
				}
				else {
					if (!crush) {
						arr[nx][ny][crush + 1] = arr[x][y][crush] + 1;
						q.push({ { nx, ny }, 1 });
					}
				}
			}
		}
	}
	return -1;
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
			arr[i][j][0] = c - '0';
		}
	}


	cout << bfs();
}