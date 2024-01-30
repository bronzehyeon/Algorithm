#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    set<string> s;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    int count = 0;
    for (int i = 0; i < M; i++) {
        string check;
        cin >> check;
        if (s.find(check) != s.end())
            count++;
    }
    cout << count;

    return 0;
}