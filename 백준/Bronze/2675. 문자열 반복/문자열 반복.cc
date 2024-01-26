#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int R;
		char word[21];
		cin >> R >> word;
		for (int j = 0; j < strlen(word); j++) {
			for (int i = 0; i < R; i++) {
				cout << word[j];
			}
		}
		cout << endl;
	}

}