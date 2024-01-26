#include <iostream>
#include <string>

using namespace std;

int main() {
	//char A[4], B[4];
	string A, B;
	cin >> A >> B;
	string bigger;
	for (int i = 2; i >= 0; i--) {
		if (A[i] > B[i]) {
			bigger = A;
			break;
		}
		if (A[i] < B[i]) {
			bigger = B;
			break;
		}
	}
	for (int i = 2; i >= 0; i--) cout << bigger[i];
}