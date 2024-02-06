#include <iostream>
#include <deque>
using namespace std;

int dataStructure[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    deque<int> element;
    
    for (int i = 0; i < N; i++) {
        int DS;
        cin >> DS;
        dataStructure[i] = DS;
    }
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        if (!dataStructure[i])
            element.push_back(d);
    }
    
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        element.push_front(c);
        cout << element.back() << " ";
        element.pop_back();
    }
}