#include <iostream>
using namespace std;

int main() {
	int A, sum;
	sum = 0;
	cin >> A;
	for (int i = 1; i <= A; i++) {
		sum += i;
	}
	cout << sum;
}