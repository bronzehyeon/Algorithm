#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1000];


    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> dp(N, 0);
    vector<vector<int>> dpv(N);
    dp[0] = 1;
    dpv[0] = {arr[0]};
    int ans = 1;
    vector<int> ansv;
    ansv.push_back(arr[0]);
    for(int i = 1; i < N; i++){
        dp[i] = 1;
        dpv[i] = {arr[i]};
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] < arr[i]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    dpv[i] = dpv[j];
                    dpv[i].push_back(arr[i]);
                }
            }
        }
        if(ans < dp[i]){
            ans = dp[i];
            ansv = dpv[i];
        }
    }
    cout<<ans<<'\n';
    for(int i = 0; i < ans; i++){
        cout<<ansv[i]<<" ";
    }
}