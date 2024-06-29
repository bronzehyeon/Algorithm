#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[101][101];
int ans[101][101];
vector<int> graph[101];

void bfs(int x) {
	bool visited[101] = { false, };
	queue<int> q;

	for (int i = 0; i < graph[x].size(); i++) {
		visited[graph[x][i]] = true;
		q.push(graph[x][i]);
	}

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		ans[x][n] = 1;

		for (int i = 0; i < graph[n].size(); i++) {
			if (!visited[graph[n][i]]) {
				visited[graph[n][i]] = true;
				q.push(graph[n][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;

			if (tmp == 1) {
				graph[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		bfs(i);
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}