#include <iostream>
#include <queue>
using namespace std;

bool visited[1000][1000];

int arr[1000][1000];
int ans[1000][1000];

int N, M;
queue<pair<pair<int, int>, int>> q;

void bfs() {
	
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int cnt = q.front().second;
		ans[a][b] = cnt > 0 ? cnt : -1;
		q.pop();

		cnt++;

		if (a + 1 < M && !visited[a + 1][b] && arr[a + 1][b] == 0) {
			q.push(make_pair(make_pair(a + 1, b), cnt));
			visited[a + 1][b] = true;
		}
		if (a - 1 >= 0 && !visited[a - 1][b] && arr[a - 1][b] == 0) {
			q.push(make_pair(make_pair(a - 1, b), cnt));
			visited[a - 1][b] = true;
		}
		if (b + 1 < N && !visited[a][b + 1] && arr[a][b + 1] == 0) {
			q.push(make_pair(make_pair(a, b + 1), cnt));
			visited[a][b + 1] = true;
		}
		if (b - 1 >= 0 && !visited[a][b - 1] && arr[a][b - 1] == 0) {
			q.push(make_pair(make_pair(a, b - 1), cnt));
			visited[a][b - 1] = true;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(make_pair(i, j), 0));
				visited[i][j] = true;
				ans[i][j] = -1;
			}
			if (arr[i][j] == -1) {
				visited[i][j] = true;
				ans[i][j] = -1;
			}
		}
	}
	
	bfs();

	int max = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (ans[i][j] > max) {
				max = ans[i][j];
			}
			if (ans[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << max;
}