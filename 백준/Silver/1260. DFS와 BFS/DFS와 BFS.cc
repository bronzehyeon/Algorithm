#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visitedDFS[1001];
bool visitedBFS[1001];

void DFS(int idx) {
	cout << idx << " ";
	visitedDFS[idx] = true;

	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (!visitedDFS[next]) {
			DFS(next);
		}
	}
}

void BFS(int idx) {
	queue<int> q;
	q.push(idx);
	visitedBFS[idx] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visitedBFS[next]) {
				q.push(next);
				visitedBFS[next] = true;
			}
		}
	}
}

int main() {

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	
	for (int i = 1; i <= N; i++) {

		sort(graph[i].begin(), graph[i].end());
	}


	DFS(V);
	cout << '\n';
	BFS(V);

}