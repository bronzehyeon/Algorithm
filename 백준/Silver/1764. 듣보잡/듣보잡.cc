#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    set<string> listen;
    set<string> see;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        listen.insert(tmp);
    }

    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        if (listen.find(tmp) != listen.end())
            see.insert(tmp);
    }

    cout << see.size() <<'\n';
    for (set<string>::iterator iter = see.begin(); iter != see.end(); iter++) {
        cout << *iter << '\n';
    }

    return 0;
}