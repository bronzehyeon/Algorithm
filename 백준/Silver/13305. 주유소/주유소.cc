#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long int answer = 0;

    vector<long long int> distance;
    vector<pair<long long int,int>> pl;

    long long int remainDistance = 0;

    distance.push_back(0);

    for (int i = 0; i < N - 1; i++) {
        long long int dis;
        cin >> dis;

        remainDistance += dis;

        distance.push_back(remainDistance);
    }

    

    for (int i = 0; i < N - 1; i++) {
        long long int price;
        cin >> price;

        pl.push_back({ price, i });
    }

    int endPrice;
    cin >> endPrice;


    sort(pl.begin(), pl.end());

    int nowLocate = N;

    for (int i = 0; i < N - 1; i++) {
        if (pl[i].second < nowLocate) {
            nowLocate = pl[i].second;
            answer += (remainDistance - distance[pl[i].second]) * pl[i].first;
            remainDistance -= remainDistance - distance[pl[i].second];
        }
        
        if (pl[i].second == 0) {
            break;
        }
    }

    cout << answer;

}