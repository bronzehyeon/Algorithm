#include <iostream>
#include <queue>
using namespace std;


int N, K;
int arr[100001];
bool visited[100001];

int tm = 2000000000;
int way = 0;

void bfs() {
	queue<pair<int, int>> q;
	visited[N] = true;
	q.push({ N, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		visited[cur] = true;

		if (cur == K && cnt <= tm) {
			tm = cnt;
			way++;
		}

		if (cur * 2 <= 100000 && visited[cur * 2] == false) {
			q.push({ cur * 2, cnt + 1 });
		}
		if (cur + 1 <= 100000 && visited[cur + 1] == false) {
			q.push({ cur + 1, cnt + 1 });
		}
		if (cur - 1 >= 0 && visited[cur - 1] == false) {
			q.push({ cur - 1, cnt + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	bfs();
	cout << tm << '\n';
	cout << way << '\n';
}

