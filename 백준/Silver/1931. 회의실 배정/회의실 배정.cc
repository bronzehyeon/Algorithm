#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v;


    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        v.push_back({ end, start });
    }

    sort(v.begin(), v.end());

    int count = 0;

    int lastMeetEnd = 0;

    for (int i = 0; i < N; i++) {
        if (v[i].second >= lastMeetEnd) {
            lastMeetEnd = v[i].first;
            count++;
        }
    }

    cout << count;
}