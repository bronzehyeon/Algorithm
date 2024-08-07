#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int arr[20][20];
bool visited[20][20];

int fish[7];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int sourcex, int sourcey, int destx, int desty, int shark) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{sourcex, sourcey} });
	visited[sourcex][sourcey] = true;

	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x == destx && y == desty) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= N || ny >= N || nx < 0 || ny < 0) {
				continue;
			}

			if (arr[nx][ny] <= shark && !visited[nx][ny]) {
				q.push({ cnt + 1, {nx, ny} });
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int solve(int sx, int sy) {
	int curx = sx;
	int cury = sy;
	int time = 0;
	int shark = 2;
	int eat = 0;

	while (true) {
		bool move = false;
		//cout << "현재 위치 : " << curx << ", " << cury << '\n';
		int min = -1;
		int nx;
		int ny;
		int size;
		for (int k = 1; k <= 6 && k < shark; k++) {
			if (fish[k]) {
				//cout << k << "먹으러 탐색" << '\n';
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (arr[i][j] == k) {
							int cnt = bfs(curx, cury, i, j, shark);
							//cout << i << ", " << j << " : " << cnt << '\n';
							if (cnt == -1) {
								continue;
							}
							else {
								if (cnt < min || min == -1) {//왼쪽 위부터 탐색하므로 cnt가 같으면 먼저 나오는게 우선
									min = cnt;
									nx = i;
									ny = j;
									size = k;
								}
								else if (cnt == min) {
									if (i < nx || (i == nx && j < ny)) {
										nx = i;
										ny = j;
										size = k;
									}
								}
							}
						}
					}
				}
				
			}
		}
		if (min != -1) {
			eat++;
			curx = nx;
			cury = ny;
			time += min;
			move = true;
			arr[nx][ny] = 0;
			fish[size]--;
			if (shark == eat) {
				eat = 0;
				shark++;
			}
			//cout << nx << ", " << ny << " 먹음 +" << min << ", 현재 사이즈 : " << shark << ", 먹은 양 : " << eat << '\n';
		}
		if (!move) {
			break;
		}
	}
	
	return time;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int sx;
	int sy;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			fish[arr[i][j]]++;
			if (arr[i][j] == 9) {
				sx = i;
				sy = j;
				arr[i][j] = 0;
			}
		}
	}

	cout << solve(sx, sy);	
}

