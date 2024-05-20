#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[101];
bool visited[101];
int bacon[101];

void BFS(int idx) {
	int cnt = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(idx, cnt));
	visited[idx] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		bacon[idx] += q.front().second;
		//cout << idx<<" -> " <<cur<<" : "<<q.front().second<<endl;
		cnt = q.front().second + 1;
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				q.push(make_pair(next,cnt));
				visited[next] = true;
			}
		}
	}
}

int main() {

	cin >> N >> M;

    for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	int min = 2147483647;
	int minIdx = 0;
	
	for (int i = 1; i <= N; i++) {
		BFS(i);
		fill(visited, visited + N + 1, false);
		//cout<<bacon[i]<<endl;
		if (bacon[i] < min) {
			min = bacon[i];
			minIdx = i;
		}
	}
	
	cout << minIdx << '\n';

}