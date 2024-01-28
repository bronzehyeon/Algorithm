#include <iostream>

using namespace std;

int main() {
    int minX = 10000, minY = 10000, maxX = -10000, maxY = -10000;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (minX > x)minX = x;
        if (minY > y)minY = y;
        if (maxX < x)maxX = x;
        if (maxY < y)maxY = y;
    }
    cout << (maxX - minX) * (maxY - minY);
}
