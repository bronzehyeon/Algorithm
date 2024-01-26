#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	int row = 1, col = 1;
	int a = -1, b = 1;
	for (int i = 1; i < X; i++) {
		if (row == 1) {
			col += 1;
			i++;
			swap(a, b);
		}
		else if (col == 1) {
			row += 1;
			i++;
			swap(a, b);
		}
		if (i >= X) break;
		row += a;
		col += b;
			
	}
	cout << row << "/" << col << '\n';

}

