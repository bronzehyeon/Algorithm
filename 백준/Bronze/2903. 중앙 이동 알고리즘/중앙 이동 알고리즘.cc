#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int start = 2;
	int tmp = 1;
	for (int i = 0; i < N; i++) {
		start += tmp;
		tmp *= 2;
	}
	cout << start * start;
}

