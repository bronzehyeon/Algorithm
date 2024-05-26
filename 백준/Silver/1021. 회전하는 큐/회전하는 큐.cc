#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	deque<int> dq;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}


	int cnt = 0;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		int idx = 0;

		while (dq[idx] != num) {
			idx++;
		}

		if (dq.size() - idx >= idx) {
			while (dq.front() != num) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		else {
			while (dq.front() != num) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		dq.pop_front();
	}

	cout << cnt;
}