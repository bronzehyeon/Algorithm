#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	int coin[] = { 25, 10, 5, 1 };
	for (int i = 0; i < T; i++){
		int C;
		cin >> C;
		for (int j = 0; j < 4; j++) {
			cout << C / coin[j] << " ";
			C %= coin[j];
		}
		cout << '\n';
	}
}
