#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<long long> A(N);
    vector<long long> B(N);
    vector<long long> C(N);
    vector<long long> D(N);

    for (int i = 0; i < N; i++) {
        //cin >> A[i] >> B[i] >> C[i] >> D[i];
        cin >> A[i];
        cin >> B[i];
        cin >> C[i];
        cin >> D[i];
    }
    vector<long long> AB;
    vector<long long> CD;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    int p1 = 0;
    int p2 = N * N - 1;

    long long ans = 0;

    while (p1 < N * N && p2 >= 0) {
        //cout << p1 << " : " << AB[p1] << ", " << p2 << " : " << CD[p2] << '\n';
        if (AB[p1] + CD[p2] == 0) {
            long long ABP = 0;
            long long CDP = 0;
            while (p1 + ABP + 1 < N * N && AB[p1] == AB[p1 + ABP + 1]) {
                ABP++;
            }
            while (p2 - CDP - 1 >= 0 && CD[p2] == CD[p2 - (CDP + 1)]) {
                CDP++;
            }
            ABP++;
            CDP++;
            ans += ABP * CDP;
            p1 += ABP;
            p2 -= CDP;
        }
        else if (AB[p1] + CD[p2] < 0) {
            p1++;
        }
        else if (AB[p1] + CD[p2] > 0) {
            p2--;
        }
    }
   
    cout << ans;
}