#include <iostream>
#include <string>
#include <vector>
#define INF 1000000
using namespace std;

int change(const string& s) {
    int mask = 0;
    for (char c : s) {
        if (c == 'A') mask |= 1<<2;
        else if (c == 'B') mask |= 1<<1;
        else if (c == 'C') mask |= 1<<0;
    }
    return mask;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin>> N;
	
	vector<int> minPrice(8,INF);
	
	for(int i = 0; i < N; i++){
		int price;
		string vitamin;
		cin>>price>>vitamin;
		
		int vita = change(vitamin);
		// cout<<vita<<'\n';
		minPrice[vita] = min(minPrice[vita], price);
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = i+1; j < 3; j++){
			// cout<<(1<<i)<<" "<<(1<<j)<<'\n';
			minPrice[1<<i|1<<j] = min(minPrice[1<<i|1<<j], minPrice[1<<i] + minPrice[1<<j]);
			// cout<<minPrice[1<<i|1<<j]<<'\n';
		}
	}
	for(int i = 0; i < 3; i++){
		minPrice[7] = min(minPrice[7], minPrice[1<<i] + minPrice[7 ^ (1<<i)]);
	}
	for(int i = 1; i <= 6; i++){
		for(int j = i + 1; j <= 6; j++){
			minPrice[i|j] = min(minPrice[i|j], minPrice[i] + minPrice[j]);
		}
	}
	if(minPrice[(1<<3) - 1] == INF){
		cout<<-1<<'\n';
	}
	else{
		cout<<minPrice[(1<<3) - 1]<<'\n';
	}
	return 0;
}