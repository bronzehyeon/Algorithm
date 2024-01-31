#include <iostream>
#include <set>
#include <map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<int, int> own;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (own.find(tmp) != own.end())
            own[tmp]++;
        else
            own.insert({ tmp, 1 });
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int check;
        cin >> check;
        cout << own[check] << " ";
    }

    return 0;
}