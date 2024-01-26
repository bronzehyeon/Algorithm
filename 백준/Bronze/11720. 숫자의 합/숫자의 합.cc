#include <iostream>
using namespace std;

int main() {
	int n;
	char num[101];
	cin >> n >> num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += int(num[i] - '0');
	}
	cout << sum;
}