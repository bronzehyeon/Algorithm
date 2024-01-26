#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	char matrix[5][15];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 15; j++) {
			matrix[i][j] = NULL;
		}
	}
	for (int i = 0; i < 5; i++) {
		cin >> matrix[i];
	}
	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (matrix[i][j] != NULL) cout << matrix[i][j];
		}
	}
	return 0;
}