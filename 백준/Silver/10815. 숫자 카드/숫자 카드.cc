#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    set<int> own;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        own.insert(tmp);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int check;
        cin >> check;
        if (own.find(check) != own.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}