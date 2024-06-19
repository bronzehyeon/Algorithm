#include <iostream>
#include <queue>
using namespace std;

bool visited[1000][1000];

int arr[1000][1000];
int ans[1000][1000];

int N, M;


void bfs(int n, int m) {
	queue<pair<pair<int,int>, int>> q;
	q.push(make_pair(make_pair(n,m), 0));
	visited[n][m] = true;

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int cnt = q.front().second;
		ans[a][b] = cnt;
		q.pop();

		if (a + 1 < N && !visited[a + 1][b] && arr[a + 1][b] == 1) {
			q.push(make_pair(make_pair(a + 1, b), cnt + 1));
			visited[a + 1][b] = true;
		}
		if (a - 1 >= 0 && !visited[a - 1][b] && arr[a - 1][b] == 1) {
			q.push(make_pair(make_pair(a - 1, b), cnt + 1));
			visited[a - 1][b] = true;
		}
		if (b + 1 < M && !visited[a][b + 1] && arr[a][b + 1] == 1) {
			q.push(make_pair(make_pair(a, b + 1), cnt + 1));
			visited[a][b + 1] = true;
		}
		if (b - 1 >= 0 && !visited[a][b - 1] && arr[a][b - 1] == 1) {
			q.push(make_pair(make_pair(a, b - 1), cnt + 1));
			visited[a][b - 1] = true;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	int destX;
	int destY;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				destX = i;
				destY = j;
			}
		}
	}
	
	bfs(destX, destY);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				cout << -1 << " ";
			}
			else {
				cout << ans[i][j] << " ";
			}
		}
		cout << '\n';
	}
}