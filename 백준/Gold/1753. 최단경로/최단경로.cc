#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[20001];
int ans[20001];

void bfs(int s) {
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, s));

	while (!q.empty()) {
		int count = -q.top().first;
		int loc = q.top().second;
		q.pop();

		if (ans[loc] < count) {
			continue;
		}

		for (int i = 0; i < graph[loc].size(); i++) {
			int next = graph[loc][i].first;
			int nextCount = count + graph[loc][i].second;
			if (next == s) {
				continue;
			}
			if (ans[next] == 0 || ans[next] > nextCount) {
				ans[next] = nextCount;
				q.push(make_pair(-nextCount, next));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	int s;
	cin >> s;

	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back(make_pair(v, w));
	}

	bfs(s);

	for (int i = 1; i <= V; i++) {
		if (ans[i] == 0 && i != s) {
			cout << "INF" << '\n';
		}
		else {
			cout << ans[i] << '\n';
		}
	}
}