#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string sample[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string tmp = "";
	string input;
	cin >> input;
	int count = 0; //크로아티아 알파벳 수
	for (int i = 0; i < input.length(); i++) {
		tmp = input[i];
		if (!tmp.compare("c")) {
			i++;
			tmp = input[i];
			if (!tmp.compare("=")) {
				count++;
			}
			else if (!tmp.compare("-")) {
				count++;
			}
			else {
				count++;
				i--;
			}
		}
		else if (!tmp.compare("d")) {
			i++;
			tmp = input[i];
			if (!tmp.compare("z")) {
				i++;
				tmp = input[i];
				if (!tmp.compare("=")) {
					count++;
				}
				else {
					count++;
					i -= 2;
				}
			}
			else if (!tmp.compare("-")) {
				count++;
			}
			else {
				count++;
				i--;
			}

		}
		else if (!tmp.compare("l")) {
			i++;
			tmp = input[i];
			if (!tmp.compare("j")) {
				count++;
			}
			else {
				count++;
				i--;
			}
		}
		else if (!tmp.compare("n")) {
			i++;
			tmp = input[i];
			if (!tmp.compare("j")) {
				count++;
			}
			else {
				count++;
				i--;
			}
		}
		else if (!tmp.compare("s")) {
			i++;
			tmp = input[i];
			if (!tmp.compare("=")) {
				count++;
			}
			else {
				count++;
				i--;
			}
		}
		else if (!tmp.compare("z")) {
			i++;
			tmp = input[i];
			if (!tmp.compare("=")) {
				count++;
			}
			else {
				count++;
				i--;
			}
		}
		else {
			count++;
		}
	}
	cout << count;
}