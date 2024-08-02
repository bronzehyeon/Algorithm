#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int arr[8][8];
int ans = 0;
vector<pair<int, int>> emp;
vector<pair<int, int>> virus;
int safe = 0;
bool visited[8][8];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int infection() {
	queue <pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first, virus[i].second });
	}

	int infected = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && arr[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				infected++;
			}
		}
	}
	return infected;
}

void wall(int idx, int cnt) {
	if (cnt == 3) {
		memset(visited, false, sizeof(visited));
		int infected = infection();
		int tmp = safe - infected- 3;
		if (tmp > ans) {
			ans = tmp;
		}
		return;
	}

	if (idx >= emp.size()) {
		return;
	}	

	arr[emp[idx].first][emp[idx].second] = 1;
	wall(idx + 1, cnt + 1);
	arr[emp[idx].first][emp[idx].second] = 0;
	wall(idx + 1, cnt);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				emp.push_back({ i,j });
				safe++;
			}
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	wall(0, 0);

	cout << ans;
}
