#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int layer = 1;
	int i = 1;
	while (layer < N) {
		layer += 6 * i;
		i++;
	}
	cout << i;
}