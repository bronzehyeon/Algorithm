#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char op[4] = { 'D','S','L','R' };

void bfs(int source, int dest) {
	queue<pair<int, string>> q;
	q.push(make_pair(source, ""));

	bool visited[10000] = { 0, };
	visited[source] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string cmd = q.front().second;
		q.pop();

		if (num == dest) {
			cout << cmd << '\n';
			break;
		}

		int arr[4];
		arr[0] = num * 2 % 10000;
		arr[1] = num - 1;
		if (arr[1] == -1) {
			arr[1] = 9999;
		}
		arr[2] = num % 1000 * 10 + num / 1000;
		arr[3] = num / 10 + num % 10 * 1000;

		for (int i = 0; i < 4; i++) {
			if (!visited[arr[i]]) {
				visited[arr[i]] = true;
				string s = cmd + op[i];
				q.push(make_pair(arr[i], s));
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

	while (N--) {
		int s, d;
		cin >> s >> d;

		bfs(s, d);
	}

	return 0;
}