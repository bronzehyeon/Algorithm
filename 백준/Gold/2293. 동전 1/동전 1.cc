#include <vector>
#include <iostream>
using namespace std;



int main() {
	
	int N, M;

	cin >> N >> M;

	vector<int> coin(N);

	for(int i = 0; i < N; i++){
		cin>>coin[i];
	}

	vector<int> dp(M+1, 0);
	dp[0] = 1;
	for(int i = 0; i < N; i++){
		for(int j = coin[i]; j <= M; j++){
			dp[j] += dp[j-coin[i]];
		}
	}
	cout<<dp[M]<<'\n';
	return 0;
}