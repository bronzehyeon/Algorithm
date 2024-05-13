#include <iostream>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    double height[50];
    int vision[50];

    for (int i = 0; i < N; i++) {
        cin >> height[i];
        vision[i] = 0;
    }

    int ans = 0;

    for (int i = 0; i < N - 1; i++) {
        double maxSlope = height[i + 1] - height[i];
        vision[i]++;
        vision[i + 1]++;
        for (int j = i + 2; j < N; j++) {
            if ((height[j] - height[i]) / (j - i) > maxSlope) {
                vision[i]++;
                vision[j]++;
                maxSlope = (height[j] - height[i]) / (j - i);
            }
        }
        if (vision[i] > ans) {
            ans = vision[i];
        }
    }
    if (vision[N - 1] > ans) {
        ans = vision[N - 1];
    }
    
    cout << ans;

}
