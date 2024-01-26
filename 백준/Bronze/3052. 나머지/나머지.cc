#include <iostream>
using namespace std;

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		arr[i] = n % 42;
	}
	int cmp[10], count = 0;
	bool duplicate = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count; j++) {
			if (arr[i] == cmp[j]) duplicate = true;
		}
		if (duplicate == false) {
			cmp[count] = arr[i];
			count++;
		}
		duplicate = false;
	}
	
	cout << count;

}