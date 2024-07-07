#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
int arr[101];
bool visited[101];
int ans = 100;

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, 0));
	visited[x] = true;

	while (!q.empty()) {
		int lotation = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (arr[lotation] != 0) {
			lotation = arr[lotation];
			visited[lotation] = true;
		}

		if (lotation == 100) {
			if (cnt < ans) {
				ans = cnt;
			}
		}
		if (cnt >= ans) {
			continue;
		}

		for (int i = 1; i <= 6 && lotation + i <= 100; i++) {
			if (!visited[lotation + i]) {
				q.push(make_pair(lotation + i, cnt + 1));
				visited[lotation + i] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	bfs(1);

	cout << ans;
}