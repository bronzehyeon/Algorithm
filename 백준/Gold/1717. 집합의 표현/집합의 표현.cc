#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> parent;

int find_parent(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if(x != y){
        parent[y] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;

    for(int i = 0; i <= N; i++){
        parent.push_back(i);
    }

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin>>a>>b>>c;

        if(a){
            if(find_parent(b) == find_parent(c)){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }
        else{
            union_parent(b,c);
        }
    }
}