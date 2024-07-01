#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int arr[25][25];
bool visited[25][25];

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 0;
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		cnt++;

		if (a + 1 < N && arr[a + 1][b] == 1 && visited[a + 1][b] == false) {
			q.push(make_pair(a + 1, b));
			visited[a + 1][b] = true;
		}
		if (b + 1 < N && arr[a][b + 1] == 1 && visited[a][b + 1] == false) {
			q.push(make_pair(a, b + 1));
			visited[a][b + 1] = true;
		}
		if (a - 1 >= 0 && arr[a - 1][b] == 1 && visited[a - 1][b] == false) {
			q.push(make_pair(a - 1, b));
			visited[a - 1][b] = true;
		}
		if (b - 1 >= 0 && arr[a][b - 1] == 1 && visited[a][b - 1] == false) {
			q.push(make_pair(a, b - 1));
			visited[a][b - 1] = true;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;



	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	vector<int> v;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				v.push_back(bfs(i, j));
			}
		}
	}

	cout << v.size() << '\n';
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}