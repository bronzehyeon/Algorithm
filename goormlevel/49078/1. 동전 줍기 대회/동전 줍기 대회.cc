#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin>>N;
	
	vector<long long> v(N);
	vector<long long> dp(N);
	
	long long answer = 0;
	
	cin>>v[0];
	dp[0] = max(v[0], 0LL);
	
	for(int i = 1; i < N; i++){
		cin>>v[i];
		dp[i] = max(dp[i-1], 0LL) + v[i];
		answer = max(answer,dp[i]);
	}
	
	cout << answer << '\n';
	
	return 0;
}