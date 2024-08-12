#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;


int N, M;
int arr[100][100];
bool visited[100][100];
bool visitedC[100][100];

int dxy[2][4] = { {1, -1, 0, 0}, {0, 0, 1, -1} };

vector<pair<int, int>> v;

void air(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		//cout << curx << " " << cury << '\n';

		arr[curx][cury] = 2;

		for (int i = 0; i < 4; i++) {
			int nx = curx + dxy[0][i];
			int ny = cury + dxy[1][i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			if (!visited[nx][ny] && arr[nx][ny] != 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
		
	}
}

bool isEnd() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

bool melt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dxy[0][i];
		int ny = y + dxy[1][i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			continue;
		}
		if (arr[nx][ny] == 2) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		return true;
	}
	else {
		return false;
	}
	
}

void hour() {
	/*
	memset(visited, false, sizeof(visited));
	air(0, 0);
	air(0, M - 1);
	air(N - 1, 0);
	air(N - 1, M - 1);
	*/
	for (int i = 0; i < v.size(); i++) {
		if (!visited[v[i].first][v[i].second]) {
			air(v[i].first, v[i].second);
		}
	}
	
	v.clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				if (melt(i, j)) {
					arr[i][j] = 0;
					v.push_back({ i, j });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;

	v.push_back({ 0, 0 });
	v.push_back({ 0, M - 1 });
	v.push_back({ N - 1, 0 });
	v.push_back({ N - 1, M - 1 });

	while (!isEnd()) {
		hour();
		ans++;
		//cout << ans << '\n';
	}

	cout << ans;
}

