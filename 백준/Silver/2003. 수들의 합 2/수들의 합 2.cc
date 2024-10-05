#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    
    for(int i = 0; i < N; i++){
        cin>>v[i];
    }
    
    int sum = 0;
    int s = 0;
    int e = 0;
    int ans = 0;
    
    while(e <= N){
        if(sum == M){
            ans++;
            sum+=v[e];
            e++;
        }
        else if(sum > M){
            sum -= v[s];
            s++;
        }
        else{
            sum += v[e];
            e++;
        }
    }
    cout<<ans;
}