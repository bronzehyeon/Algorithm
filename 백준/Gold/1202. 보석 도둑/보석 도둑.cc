#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

vector<pair<int, int>> v;
vector<int> bag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int m, val;
        cin >> m >> val;

        v.push_back({ m, val });
    }

    for (int i = 0; i < K; i++) {
        int size;
        cin >> size;
        bag.push_back(size);
    }

    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());

    long long ans = 0;

    priority_queue<int> pq;
    int idx = 0;

    for (int i = 0; i < K; i++) {
        for(; idx < N; idx++){
            if(bag[i] < v[idx].first){
                break;
            }
            pq.push(v[idx].second);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}