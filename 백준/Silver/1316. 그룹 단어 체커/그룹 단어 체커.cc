#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int count[26];
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int i = 0; i < 26; i++) {
			count[i] = 0;
		}
		bool isGroup = true;
		char now = ' ';
		string word;
		cin >> word;
		for (int j = 0; j < word.length(); j++) {
			if (word[j] != now) {
				count[int(word[j] - 'a')]++;
				now = word[j];
			}
		}
		for (int i = 0; i < 26; i++) {
			if (count[i] > 1) {
				isGroup = false;
			}
		}
		if (isGroup) answer++;
	}
	cout << answer;
}