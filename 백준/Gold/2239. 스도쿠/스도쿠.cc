#include <iostream>
#include <string>
using namespace std;

string str;

int arr[10][10];

bool ans = false;

bool check (int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (i == y) {
			continue;
		}
		if (arr[x][i] == num) {
			return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == x) {
			continue;
		}
		if (arr[i][y] == num) {
			return false;
		}
	}
	int sectorX = x / 3 * 3;
	int sectorY = y / 3 * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sectorX + i == x && sectorY + j == y) {
				continue;
			}
			//cout << sectorX + i << " " << sectorY + j << '\n';
			if (arr[sectorX + i][sectorY + j] == num) {
				return false;
			}
		}
	}
	return true;
}

void sudoku(int x, int y) {
	if (arr[x][y] == 0) {
		for (int k = 1; k <= 9; k++) {
			if (check(x, y, k)) {
				arr[x][y] = k;
				if (x == 8 && y == 8) {
					ans = true;
					for (int i = 0; i < 9; i++) {
						for (int j = 0; j < 9; j++) {
							cout << arr[i][j];
						}
						cout << '\n';
					}
					return;
				}
				if (y == 8) {
					sudoku(x + 1, 0);
				}
				else {
					sudoku(x, y + 1);
				}
				if (ans) {
					return;
				}
			}
			if (k == 9) {
				arr[x][y] = 0;
				return;
			}
		}
	}
	else {
		if (x == 8 && y == 8) {
			ans = true;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << arr[i][j];
				}
				cout << '\n';
			}
			return;
		}
		if (y == 8) {
			sudoku(x + 1, 0);
		}
		else {
			sudoku(x, y + 1);
		}
		if (ans) {
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++) {
			arr[i][j] = str[j] -'0';
		}
	}
	


	sudoku(0, 0);
}

