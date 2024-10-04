#include <vector>
#include <iostream>
using namespace std;

vector<int> parent;

int find_parent(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find_parent(parent[x]);
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

    for(int i = 1; i <= N; i++){
        for(int j = 1; j<=N;j++){
            int tmp;
            cin>> tmp;
            int x = i;
            int y = j;
            if(tmp == 1){
                x = find_parent(x);
                y = find_parent(y);
                if(x != y){
                    if(x < y)
                        parent[y] = x;
                    else
                        parent[x] = y;
                }
            }
        }
    }
    bool isCan = true;
    int start;
    cin>> start;
    int par = find_parent(start);
    for(int i = 0; i < M - 1; i++){
        int course;
        cin>>course;
        if(find_parent(course) != par){
            isCan = false;
        }
    }
    if(isCan){
        cout <<"YES";
    }
    else{
        cout<<"NO";
    }
}