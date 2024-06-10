#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;

	for(int i = 0; i<3;i++){
		string s;
		cin >> s;
		if (s != "Fizz" && s != "Buzz" && s != "FizzBuzz") {
			ans = stoi(s) + 3 - i;
		}
	}
		
	if (ans % 3 == 0 && ans % 5 == 0) {
		cout << "FizzBuzz" << '\n';
	}	
	else if (ans % 3 == 0) {
		cout << "Fizz" << '\n';
	}	
	else if ( ans % 5 == 0) {
		cout << "Buzz" << '\n';
	}
	else {
		cout << ans << '\n';
	}
	

}