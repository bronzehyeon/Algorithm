#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int R, C, T;

int arr[50][50];
int pd[50][50];

int uA = -1;
int dA = -1;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int, int>> v;
void UAC() {
	int dx = -1;
	int dy = 0;
	int cx = uA;
	int cy = 0;
	while (true) {
		if (cx == 0 && cy == 0) {
			dx = 0;
			dy = 1;
		}
		if (cx == 0 && cy == C - 1) {
			dx = 1;
			dy = 0;
		}
		if (cx == uA && cy == C - 1) {
			dx = 0;
			dy = -1;
		}

		int nx = cx + dx;
		int ny = cy + dy;

		if (nx == uA && ny == 0)
			break;

		if (cx == uA && cy == 0) {
			arr[nx][ny] = 0;
		}
		else {
			arr[cx][cy] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		cx = nx;
		cy = ny;
	}
}
void DAC() {
	int dx = 1;
	int dy = 0;
	int cx = dA;
	int cy = 0;
	while (true) {
		if (cx == R - 1 && cy == 0) {
			dx = 0;
			dy = 1;
		}
		if (cx == R - 1 && cy == C - 1) {
			dx = -1;
			dy = 0;
		}
		if (cx == dA && cy == C - 1) {
			dx = 0;
			dy = -1;
		}

		int nx = cx + dx;
		int ny = cy + dy;

		if (nx == dA && ny == 0)
			break;

		if (cx == dA && cy == 0) {
			arr[nx][ny] = 0;
		}
		else {
			arr[cx][cy] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		cx = nx;
		cy = ny;
	}
}

void cycle() {
	int N = v.size();
	for (int n = 0; n < N; n++) {
		int x = v[n].first;
		int y = v[n].second;

		int dust = arr[x][y] / 5;
		
		int dir = 0;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx >= R || ny >= C || nx < 0 || ny < 0 || ((nx == uA || nx == dA) && ny == 0)) {
				continue;
			}
			dir++;
			pd[nx][ny] += dust;
		}
		arr[x][y] -= dust * dir;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (pd[i][j] > 0) {
				arr[i][j] += pd[i][j];
				pd[i][j] = 0;
			}
		}
	}

	UAC();
	DAC();

	v.clear();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0) {
				v.push_back({ i,j });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];

			if (arr[i][j] > 0) {
				v.push_back({ i,j });
			}

			if (arr[i][j] == -1) {
				if (uA == -1) {
					uA = i;
				}
				else {
					dA = i;
				}
			}
		}
	}

	while (T--) {
		cycle();
	}

	int sum = 2;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			sum += arr[i][j];
			//cout << arr[i][j] << ' ';

		}
		//cout << '\n';
	}

	cout << sum;
}

