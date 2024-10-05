#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    sort(v.begin(), v.end());
    
    int s = 0;
    int e = N-1;
    int ans = 0;
    while(s < e){
        int sum = v[s]+v[e];
        if(sum == x){
            ans++;
            s++;
            e--;
        }
        else if(sum > x){
            e--;
        }
        else{
            s++;
        }
    }
    cout<<ans;
}