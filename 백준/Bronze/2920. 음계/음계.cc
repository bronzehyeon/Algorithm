#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[8];

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 7; i++) {
		if (arr[i] + 1 != arr[i + 1]) {
			break;
		}
		if (i == 6) {
			cout << "ascending";
			return 0;
		}
	}
	for (int i = 0; i < 7; i++) {
		if (arr[i] - 1 != arr[i + 1]) {
			break;
		}
		if (i == 6) {
			cout << "descending";
			return 0;
		}
	}
	cout << "mixed";


}