#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[100];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int v, count = 0;
	cin >> v;
	for (int i = 0; i < N; i++) {
		if (v == arr[i]) count++;
	}
	cout << count;
}