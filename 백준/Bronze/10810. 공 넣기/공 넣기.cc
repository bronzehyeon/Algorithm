#include <iostream>
using namespace std;

int main() {
	int arr[100];
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
	}
	for (int x = 0; x < M; x++) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int y = i - 1; y <= j - 1; y++) {
			arr[y] = k;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}