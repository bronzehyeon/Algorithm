#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[1000000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int min = 1000000, max = -1000000;
	for (int i = 0; i < N; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	cout << min << " " << max;
}