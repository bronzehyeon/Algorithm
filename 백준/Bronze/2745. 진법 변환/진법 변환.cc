#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
	string str;
	int n;
	cin >> str >> n;
	int i = 0;
	int answer = 0;
	while (str[i] != NULL) {
		int tmp;
		if (str[i] >= 'A') {
			tmp = str[i] - 'A' + 10;
		}
		else {
			tmp = str[i] - '0';
		}
		for (int j = 0; j < str.length() - 1 - i; j++) {
			tmp *= n;
		}
		answer += tmp;
		i++;
	}
	cout << answer;
	return 0;
}