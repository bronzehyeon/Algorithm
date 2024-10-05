#include <vector>
#include <iostream>

using namespace std;
    

int main() {

	int N, M;
	cin>>N>>M;
	vector<pair<int,pair<int,int>>> v(M);
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin>>a>>b>>c;

		v[i] = {a,{b,c}};
	}

	vector<long long> dist(N+1, 1000000000);
	dist[1] = 0;

	for(int n = 0; n < N; n++){
		for(int i = 0; i < M; i++){
			int s = v[i].first;
			int e = v[i].second.first;
			long long d = v[i].second.second;

			if(dist[s] == 1000000000){
			    continue;
			}

			if(dist[e] > dist[s] + d){
				if(n == N-1){
					cout<<-1<<'\n';
					return 0;
				}
				dist[e] = dist[s] + d;
			}
		}
	}
	for(int i = 2; i <= N; i++){
		if(dist[i] == 1000000000){
			cout << -1<<'\n';
		}
		else{
			cout<<dist[i]<<'\n';
		}
	}

	return 0;
}