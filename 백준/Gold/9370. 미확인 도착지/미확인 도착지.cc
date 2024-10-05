#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <map>

using namespace std;
    

int main() {

	int T;
	cin >> T;
	
	while(T--){
		int n,m,t;
		cin>>n>>m>>t;
		int s,g,h;
		cin>>s>>g>>h;
		
		vector<vector<pair<int,int>>> graph(n+1);
		
		for(int i = 0; i < m; i++){
			int a,b,d;
			cin>>a>>b>>d;
			
			graph[a].push_back({b,d});
			graph[b].push_back({a,d});
		}
		
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		pq.push({0,s});

        vector<int> ds(n + 1, 1000000000);

		ds[s] = 0;
		
		while(!pq.empty()){
			int cur = pq.top().second;
			int cnt = pq.top().first;
			pq.pop();

            if(ds[cur] < cnt){
                continue;
            }
			
			for(int i = 0; i < graph[cur].size(); i++){
				int next = graph[cur][i].first;
				int ndist= graph[cur][i].second + cnt;
				
				if(ds[next] == -1 || ds[next] > ndist){
					pq.push({ndist,next});
					ds[next] = ndist;
				}
			}
		}

        vector<int> dg(n + 1, -1);

		pq.push({0,g});

        dg[g] = 0;
		
		while(!pq.empty()){
			int cur = pq.top().second;
			int cnt = pq.top().first;
			pq.pop();
			

            if(dg[cur] < cnt){
                continue;
            }

			for(int i = 0; i < graph[cur].size(); i++){
				int next = graph[cur][i].first;
				int ndist= graph[cur][i].second + cnt;
				
				if(dg[next] == -1 || dg[next] > ndist){
					pq.push({ndist,next});
					dg[next] = ndist;
				}
			}
		}

		vector<int> dh(n + 1, 1000000000);

		pq.push({0,h});
		dh[h] = 0;
		
		while(!pq.empty()){
			int cur = pq.top().second;
			int cnt = pq.top().first;
			pq.pop();

            if(dh[cur] < cnt){
                continue;
            }
			
			for(int i = 0; i < graph[cur].size(); i++){
				int next = graph[cur][i].first;
				int ndist= graph[cur][i].second + cnt;
				
				if(dh[next] == -1 || dh[next] > ndist){
					pq.push({ndist,next});
					dh[next] = ndist;
				}
			}
		}
		
		set<int> dest;
        int gh = dg[h];
		for(int i = 0; i < t; i++){
			int x;
            cin>>x;
            if(ds[x] == ds[g] + gh + dh[x] || ds[x] == ds[h] + gh + dg[x]){
                dest.insert(x);
            }
		}
        auto iter = dest.begin();

        while(iter != dest.end()){
            cout<<*iter<<" ";
            iter++;
        }
        cout<<'\n';
		
	}
	
	return 0;
}