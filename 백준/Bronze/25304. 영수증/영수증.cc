#include <iostream>
using namespace std;

int main() {
	int total, N;
	cin >> total;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int price, quantity;
		cin >> price >> quantity;
		sum += price * quantity;
	}
	if (total == sum) cout << "Yes";
	else cout << "No";
}