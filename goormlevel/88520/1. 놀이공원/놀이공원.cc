#include <iostream>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	
	while(T--){
		int N,K;
		cin >> N >> K;
		vector<vector<int>> v(N,vector<int>(N));
		vector<vector<int>> trash(N,vector<int>(N, 0));
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin>>v[i][j];
				// cout<<v[i][j]<< " ";
				if(v[i][j] == 1){
					for(int a = 0; a < K && a + i < N; a++){
						for(int b = 0; b<K && b + j < N; b++){
							trash[i + a][j + b]++;
						}
					}
				}
			}
			// cout<<'\n';
		}
		int answer = K * K;
		for(int i = K - 1; i < N; i++){
			for(int j = K - 1; j < N; j++){
				answer = min(answer, trash[i][j]);
			}
		}
		
		cout<<answer<<'\n';
	}
	
	
	return 0;
}