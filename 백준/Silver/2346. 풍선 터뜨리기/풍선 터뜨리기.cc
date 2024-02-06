#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    deque<int> deq;
    deque<int> ballon;
    string str;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        deq.push_back(num);
        ballon.push_back(i);
    }
    int move = 1;
    while (!deq.empty()) {
        if (move > 0) {
            for (int i = 1; i < move; i++) {
                int tmp = deq.front();
                deq.pop_front();
                deq.push_back(tmp);
                tmp = ballon.front();
                ballon.pop_front();
                ballon.push_back(tmp);
            }
        }
        else {
            move = -move;
            for (int i = 1; i <= move; i++) {
                int tmp = deq.back();
                deq.pop_back();
                deq.push_front(tmp);
                tmp = ballon.back();
                ballon.pop_back();
                ballon.push_front(tmp);
            }
        }
        cout << ballon.front() << " ";
        move = deq.front();
        deq.pop_front();
        ballon.pop_front();
    }
}