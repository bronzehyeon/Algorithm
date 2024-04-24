#include <iostream>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        long distance = y - x;
        long count = sqrt(distance);

        while (true) {
            if (count * (count + 1) >= distance) {
                break;
            }
            count++;
        }
        if (count * (count + 1) - count >= distance) {
            cout << count * 2 - 1 << '\n';
        }
        else {
            cout << count * 2 << '\n';
        }
        
    }
    
}

