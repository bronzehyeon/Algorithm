#include <iostream>
#include <cstring>
using namespace std;

char star[3100][6200];

void rec(int x, int y, int n) {
	if (n == 3) {
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 1][y + 1] = '*';
		for (int i = -2; i <= 2; i++) {
			star[x + 2][y + i] = '*';
		}
	}
	else {
		rec(x, y, n / 2);
		rec(x + n / 2, y - n / 2, n / 2);
		rec(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	memset(star, ' ', sizeof(star));

	rec(0, N - 1, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}

