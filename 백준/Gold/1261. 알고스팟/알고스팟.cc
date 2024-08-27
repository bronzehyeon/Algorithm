#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int maze[100][100];
bool visited[100][100];
int cost[100][100];

int dxy[2][4] = { {1,-1,0,0}, {0,0,1,-1} };

void bfs() {
	queue < pair<int, pair<int, int>>> q;
	q.push({ 0,{0,0} });
	cost[0][0] = 0;

	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		//cout << x << " " << y << '\n';

		if (cnt > cost[x][y]) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dxy[0][i];
			int ny = y + dxy[1][i];
			int ncnt = cnt + maze[nx][ny];

			if (nx >= N || ny >= M || nx < 0 || ny < 0) {
				continue;
			}

			if (ncnt < cost[nx][ny]) {
				cost[nx][ny] = ncnt;
				q.push({ ncnt,{nx,ny} });
			}
		}
	}

}


int main() {

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			maze[i][j] = s[j] - '0';
			visited[i][j] = false;
			cost[i][j] = 20000;
		}
	}

	bfs();

	cout << cost[N - 1][M - 1] << endl;


}