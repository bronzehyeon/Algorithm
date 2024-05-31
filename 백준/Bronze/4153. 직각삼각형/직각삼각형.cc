#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int arr[3];

		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
		}
		if (arr[0] == 0) {
			break;
		}

		sort(arr, arr + 3);

		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}


	}
}