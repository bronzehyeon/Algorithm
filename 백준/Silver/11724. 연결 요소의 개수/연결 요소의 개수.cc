#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 0; i < graph[a].size(); i++) {
			int b = graph[a][i];
			if (!visited[b]) {
				q.push(b);
				visited[b] = true;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';
	
}