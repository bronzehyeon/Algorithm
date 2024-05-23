#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
int arr[101][101] = { 0, };
bool visited[101][101] = { 0, };

int ans = 2147483647;

void BFS() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	arr[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			ans = min(ans, arr[x][y]);
		}

		if (x - 1 >= 0 && maze[x - 1][y] == 1 && !visited[x - 1][y]) {
			q.push({ x - 1, y });
			visited[x - 1][y] = true;
			arr[x - 1][y] = arr[x][y] + 1;
		}
		if (x + 1 < N && maze[x + 1][y] == 1 && !visited[x + 1][y]) {
			q.push({ x + 1, y });
			visited[x + 1][y] = true;
			arr[x + 1][y] = arr[x][y] + 1;
		}
		if (y - 1 >= 0 && maze[x][y - 1] == 1 && !visited[x][y - 1]) {
			q.push({ x, y - 1 });
			visited[x][y - 1] = true;
			arr[x][y - 1] = arr[x][y] + 1;
		}
		if (y + 1 < M && maze[x][y + 1] == 1 && !visited[x][y + 1]) {
			q.push({ x, y + 1 });
			visited[x][y + 1] = true;
			arr[x][y + 1] = arr[x][y] + 1;
		}
	}
}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			maze[i][j] = s[j] - '0';
		}
	}

	BFS();

	cout << ans;


}