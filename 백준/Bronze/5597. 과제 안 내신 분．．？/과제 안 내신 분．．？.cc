#include <iostream>
using namespace std;

int main() {
	int arr[30];
	for (int i = 0; i < 30; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < 28; i++) {
		int n;
		cin >> n;
		arr[n - 1] = 0;
	}
	for (int i = 0; i < 30; i++) {
		if (arr[i] != 0) cout << arr[i] << endl;
	}
}