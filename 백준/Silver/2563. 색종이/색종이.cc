#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int Area = 0;
	int paper[100][100];
	int N;
	cin >> N;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			paper[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				paper[A - 1 + i][B - 1 + j] = 1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			Area += paper[i][j];
		}
	}
	cout << Area;
	return 0;
}