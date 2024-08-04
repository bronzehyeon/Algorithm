#include <iostream>
#include <string>
using namespace std;

int R, C;

char arr[20][20];
bool visited[20][20];

bool alphabet[26];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int ans = 0;

void dfs(int x, int y, int cnt) {
	if (cnt > ans) {
		ans = cnt;
	}
	//cout << x << " " << y << " " << cnt << '\n';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
			continue;
		}

		if (!visited[nx][ny] && !alphabet[arr[nx][ny] - 'A']) {
			alphabet[arr[nx][ny] - 'A'] = true;
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1);
			alphabet[arr[nx][ny] - 'A'] = false;
			visited[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			arr[i][j] = s[j];
		}
	}

	alphabet[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;
}
