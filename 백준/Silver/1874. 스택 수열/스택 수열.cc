#include <iostream>
#include <stack>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int max = 0;

	stack<int> s;
	queue<char> q;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > max) {
			for (int j = max + 1; j <= tmp; j++) {
				s.push(j);
				q.push('+');
			}
			max = tmp;
			s.pop();
			q.push('-');
		}
		else {
			if (s.top() == tmp) {
				s.pop();
				q.push('-');
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	int size = q.size();
	
	for (int i = 0; i < size; i++) {
		cout << q.front() << '\n';
		q.pop();
	}

}