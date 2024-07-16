#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<int> graph[100001];
int arr[100001];

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));

	while (!q.empty()) {
		int now = q.front().first;
		int from = q.front().second;
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			if (graph[now][i] != from) {
				q.push(make_pair(graph[now][i], now));
				arr[graph[now][i]] = now;
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

	int t = N - 1;

	while (t--) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	bfs();

	for (int i = 2; i <= N; i++) {
		cout << arr[i] << '\n';
	}
}