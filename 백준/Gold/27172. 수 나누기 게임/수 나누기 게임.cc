#include <iostream>
using namespace std;

int N;

int ans[100001];

int master[1000001];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int card;
		cin >> card;

		master[card] = i;
		ans[i] = 0;
	}

	

	for (int i = 1; i <= 1000000; i++) {
		if (master[i] == 0) {
			continue;
		}

		int player = master[i];

		for (int j = 2; j * i <= 1000000; j++) {
			int loser = master[j * i];
			ans[player] += (master[j * i] ? 1 : 0);
			ans[loser]--;
		}
	}



	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	

}