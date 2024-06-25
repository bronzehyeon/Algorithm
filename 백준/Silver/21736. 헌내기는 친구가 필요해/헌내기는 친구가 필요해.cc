#include <iostream>
#include <queue>
using namespace std;

int N, M;
char arr[600][600];
int cnt = 0;
bool visited[600][600];

void bfs(int dx, int dy) {
	queue<pair<int, int >> q;
	q.push(make_pair(dx, dy));
	visited[dx][dy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (arr[x][y] == 'P') {
			cnt++;
		}
		q.pop();

		if (x + 1 < N && visited[x + 1][y] == false) {
			visited[x + 1][y] = true;
			q.push(make_pair(x + 1, y));
		}
		if (y + 1 < M && visited[x][y + 1] == false) {
			visited[x][y + 1] = true;
			q.push(make_pair(x, y + 1));
		}
		if (x - 1 >= 0 && visited[x - 1][y] == false) {
			visited[x - 1][y] = true;
			q.push(make_pair(x - 1, y));
		}
		if (y - 1 >= 0 && visited[x][y - 1] == false) {
			visited[x][y - 1] = true;
			q.push(make_pair(x, y - 1));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	int dx;
	int dy;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				dx = i;
				dy = j;
			}
			if (arr[i][j] == 'X') {
				visited[i][j] = true;
			}
		}
	}
	
	bfs(dx, dy);
	if (cnt == 0) {
		cout << "TT" << '\n';
	}
	else {
		cout << cnt << '\n';
	}
}