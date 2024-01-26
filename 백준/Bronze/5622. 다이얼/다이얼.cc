#include <iostream>
#include <string>

using namespace std;

int main() {
	int group[] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	string num;
	cin >> num;
	int sum = 0;
	for (int i = 0; i < num.length(); i++)
	{
		int index = int(num[i]-'A');
		sum += group[index];
	}
	cout << sum;
}