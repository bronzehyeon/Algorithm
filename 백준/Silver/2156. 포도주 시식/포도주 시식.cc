#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int direct[10000];
    int skip[10000];
    int doubleskip[10000];


    int N;
    cin >> N;


    for (int i = 0; i < N; i++) {
        cin >> direct[i];
        skip[i] = direct[i];
        doubleskip[i] = direct[i];
    }
    if (N > 1)
        direct[1] += direct[0];
    if (N > 2) {
        skip[2] += direct[0];
        direct[2] += skip[1];
    }

    int maxWine = max(direct[0], direct[1]);

    for (int i = 3; i < N; i++) {
        direct[i] += max(skip[i - 1], doubleskip[i-1]);
        skip[i] += max({ doubleskip[i - 2], skip[i - 2], direct[i - 2] });
        doubleskip[i] += max({ doubleskip[i - 3], skip[i - 3], direct[i - 3] });
        if (maxWine < max({ direct[i], skip[i], doubleskip[i] }))
            maxWine = max(direct[i], skip[i]);
    }

    cout << maxWine;

}