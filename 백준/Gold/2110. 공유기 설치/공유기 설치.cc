#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int solve(int N, int C) {

    int s = 0;
    int e = v[N - 1] - v[0];

    int answer = 0;

    while (s <= e) {

        int count = 1;

        int mid = (s + e) / 2;

        int start = v[0];

        for (int i = 1; i < N; ++i) {

            int end = v[i];

            if (end - start >= mid) {
                count += 1;
                start = end;
            }
        }

        if (count >= C) {
            answer = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    return answer;

}

int main() {

    int N, C;
    cin >> N >> C;


    
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cout << solve(N, C);

}