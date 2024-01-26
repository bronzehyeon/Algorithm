#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	char word[101];
	cin >> word;
	char backup[101] = "";
	//strcpy_s(backup, word);
	for (int i = 0; i < strlen(word); i++) {
		backup[i] = word[i];
	}
	reverse(word, word + strlen(word));
	//cout << backup << " " << word << endl;
	cout << !strcmp(word, backup);
	//if (!strcmp(word, backup)) { cout << 1; }
	//else {cout << 0;}
}