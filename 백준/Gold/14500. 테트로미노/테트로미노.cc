#include <iostream>
#include <queue>
using namespace std;

int N, M;
int ans = 0;
bool visited[500][500];
int arr[500][500];

void dfs(int x, int y, int cnt, int sum) {

	if (cnt == 4) {
		if (sum + arr[x][y] > ans) {
			ans = sum + arr[x][y];
		}
		return;
	}

	if (x + 1 < N && !visited[x + 1][y]) {
		visited[x + 1][y] = true;
		dfs(x + 1, y, cnt + 1, sum + arr[x][y]);
		visited[x + 1][y] = false;
	}
	if (x - 1 >= 0 && !visited[x - 1][y]) {
		visited[x - 1][y] = true;
		dfs(x - 1, y, cnt + 1, sum + arr[x][y]);
		visited[x - 1][y] = false;
	}
	if (y + 1 < N && !visited[x][y + 1]) {
		visited[x][y + 1] = true;
		dfs(x, y + 1, cnt + 1, sum + arr[x][y]);
		visited[x][y + 1] = false;
	}
	if (y - 1 >= 0 && !visited[x][y - 1]) {
		visited[x][y - 1] = true;
		dfs(x, y - 1, cnt + 1, sum + arr[x][y]);
		visited[x][y - 1] = false;
	}
}

void hat(int x, int y) {
	if (x > 0 && y > 0 && x + 1 < N) {
		int sum = arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x + 1][y];
		if (sum > ans) {
			ans = sum;
		}
	}
	if (x > 0 && y > 0 && y + 1 < M) {
		int sum = arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1];
		if (sum > ans) {
			ans = sum;
		}
	}
	if (x + 1 < N && y + 1 < M && x - 1 >= 0) {
		int sum = arr[x][y] +  arr[x - 1][y] + arr[x][y + 1] + arr[x + 1][y];
		if (sum > ans) {
			ans = sum;
		}
	}
	if (x + 1 < N && y + 1 < M && y - 1 >= 0) {
		int sum = arr[x][y] + arr[x][y - 1] + arr[x][y + 1] + arr[x + 1][y];
		if (sum > ans) {
			ans = sum;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, 0);
            visited[i][j] = false;
            hat(i, j);
        }
    }

    cout << ans << '\n';
	return 0;
}