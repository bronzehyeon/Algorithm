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
    dp[0] = arr[0];
    int ans = arr[0];
    for(int i = 1; i < N; i++){
        dp[i] = arr[i];
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans;
}