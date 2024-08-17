#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, R, Q;
vector<int> graph[100001];
int parent[100001];
int ans[100001];
int depth[100001];

void bfs(int x) {
	queue<pair<pair<int, int>, int>> q;

	q.push({ { x , -1 }, 0 });

	while (!q.empty()) {
		int cur = q.front().first.first;
		int prev = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		depth[cur] = cnt;

		for(int i = 0; i < graph[cur].size(); i++){
			int next = graph[cur][i];
			if (next != prev) {
				parent[next] = cur;
				q.push({{ next, cur }, cnt + 1});
			}
		}
	}
}


void sol() {
	priority_queue < pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		ans[i] = 1;
		q.push({ depth[i], i });
	}

	while (!q.empty()) {
		int cur = q.top().second;
		int par = parent[cur];
		q.pop();
		//cout << cur << " " << ans[cur] << '\n';

		ans[par] += ans[cur];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;
	
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bfs(R);
	//cout << "bfs" << '\n';
	sol();

	/*for (int i = 1; i <= N; i++) {
		cout << i << " : " << ans[i] << '\n';
	}*/

	while (Q--) {
		int q;
		cin >> q;

		cout << ans[q] << '\n';
	}
	
	
}

