#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N;
char arr1[100][100];
char arr2[100][100];
bool visited1[100][100];
bool visited2[100][100];

void bfs1(int x, int y) {
	char base = arr1[x][y];
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	visited1[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a + 1 < N && !visited1[a + 1][b] && arr1[a + 1][b] == base) {
			visited1[a + 1][b] = true;
			q.push(make_pair(a + 1, b));
		}
		if (b + 1 < N && !visited1[a][b + 1] && arr1[a][b + 1] == base) {
			visited1[a][b + 1] = true;
			q.push(make_pair(a, b + 1));
		}
		if (a - 1 >= 0 && !visited1[a - 1][b] && arr1[a - 1][b] == base) {
			visited1[a - 1][b] = true;
			q.push(make_pair(a - 1, b));
		}
		if (b - 1 >= 0 && !visited1[a][b - 1] && arr1[a][b - 1] == base) {
			visited1[a][b - 1] = true;
			q.push(make_pair(a, b - 1));
		}
	}
}

void bfs2(int x, int y) {
	char base = arr2[x][y];
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	visited2[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a + 1 < N && !visited2[a + 1][b] && arr2[a + 1][b] == base) {
			visited2[a + 1][b] = true;
			q.push(make_pair(a + 1, b));
		}
		if (b + 1 < N && !visited2[a][b + 1] && arr2[a][b + 1] == base) {
			visited2[a][b + 1] = true;
			q.push(make_pair(a, b + 1));
		}
		if (a - 1 >= 0 && !visited2[a - 1][b] && arr2[a - 1][b] == base) {
			visited2[a - 1][b] = true;
			q.push(make_pair(a - 1, b));
		}
		if (b - 1 >= 0 && !visited2[a][b - 1] && arr2[a][b - 1] == base) {
			visited2[a][b - 1] = true;
			q.push(make_pair(a, b - 1));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr1[i][j];
			arr2[i][j] = arr1[i][j];

			if (arr2[i][j] == 'R') {
				arr2[i][j] = 'G';
			}
		}
	}

	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited1[i][j]) {
				cnt1++;
				bfs1(i, j);
			}
			if (!visited2[i][j]) {
				cnt2++;
				bfs2(i, j);
			}
		}
	}

	cout << cnt1 << " " << cnt2;
}