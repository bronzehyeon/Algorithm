#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int arr[16][16];
int ans = 0;

void bfs() {
	queue <pair< pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{0,1} });

	while (!q.empty()) {
		int fr = q.front().first.first;
		int fc = q.front().first.second;
		int sr = q.front().second.first;
		int sc = q.front().second.second;
		q.pop();

		if (sr == N - 1 && sc == N - 1) {
			ans++;
			continue;
		}
		
		if (fr == sr) {//일자로 누워있는 경우
			if (sc + 1 < N && !arr[sr][sc + 1]) {
				q.push({ {sr,sc},{sr, sc + 1} });
			}
			if (sc + 1 < N && sr + 1 < N && !arr[sr][sc + 1] && !arr[sr + 1][sc] && !arr[sr + 1][sc + 1]) {
				q.push({ {sr,sc},{sr + 1, sc + 1} });
			}
		}
		else if (fc == sc) {//일자로 서있는 경우
			if (sr + 1 < N && !arr[sr + 1][sc]) {
				q.push({ {sr,sc},{sr + 1, sc} });
			}
			if (sc + 1 < N && sr + 1 < N && !arr[sr][sc + 1] && !arr[sr + 1][sc] && !arr[sr + 1][sc + 1]) {
				q.push({ {sr,sc},{sr + 1, sc + 1} });
			}
		}
		else {//대각선인 경우
			if (sc + 1 < N && !arr[sr][sc + 1]) {
				q.push({ {sr,sc},{sr, sc + 1} });
			}
			if (sr + 1 < N && !arr[sr + 1][sc]) {
				q.push({ {sr,sc},{sr + 1, sc} });
			}
			if (sc + 1 < N && sr + 1 < N && !arr[sr][sc + 1] && !arr[sr + 1][sc] && !arr[sr + 1][sc + 1]) {
				q.push({ {sr,sc},{sr + 1, sc + 1} });
			}
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
			cin >> arr[i][j];
		}
	}

	bfs();

	cout << ans;
}
