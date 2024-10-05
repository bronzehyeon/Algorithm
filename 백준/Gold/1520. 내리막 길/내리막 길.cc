#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<vector<int>> dp;
vector<vector<int>> v;
int dxy[2][4] = {{1,-1,0,0},{0,0,1,-1}};

int dfs(int x, int y){
	int cnt = 0;

	for(int i = 0; i < 4; i++){
		int nx = x + dxy[0][i];
		int ny = y + dxy[1][i];

		if(nx < 0 || ny < 0 || nx >= N || ny >= M || v[nx][ny] >= v[x][y]){
			continue;
		}
		if(dp[nx][ny] != -1){
			cnt += dp[nx][ny];
		}
		else{
			cnt += dfs(nx, ny);
		}
	}
	dp[x][y] = cnt;
	return cnt;
}

int main() {

	cin>>N>>M;
	dp.resize(N,vector<int>(M,-1));
	v.resize(N,vector<int>(M));

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> v[i][j];
		}
	}
	dp[N-1][M-1] = 1;
	dfs(0,0);
	
	cout<<dp[0][0]<<'\n';


	return 0;
}