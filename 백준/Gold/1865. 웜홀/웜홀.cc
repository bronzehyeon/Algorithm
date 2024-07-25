#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	while (TC--) {
		int N, M, W;
		cin >> N >> M >> W;

		vector<pair<int, int>> graph[501];
		int rt[501];

		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			graph[S].push_back({ E,T });
			graph[E].push_back({ S,T });
		}
		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			graph[S].push_back({ E, -T });
		}


		for (int t = 0; t < N; t++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 0; j < graph[i].size(); j++) {
					int cur = i;
					int next = graph[i][j].first;
					int time = graph[i][j].second;

					if (rt[cur] + time < rt[next]) {
						rt[next] = rt[cur] + time;
					}
				}
			}
		}

		bool isMeet = false;

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int cur = i;
				int next = graph[i][j].first;
				int time = graph[i][j].second;

				if (rt[cur] + time < rt[next]) {
					isMeet = true;
					break;
				}
			}
			if (isMeet) break;
		}
		if (isMeet) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		
	}

}