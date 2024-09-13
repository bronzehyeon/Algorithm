#include <iostream>
using namespace std;

long long x1, y1, x2, y2, x3, y3,  x4, y4;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (res < 0)
        return -1;
    if (res > 0) {
        return 1;
    }
    return 0;
}

bool isLine(int a, int b, int c, int d)
{
    if (a > b)
    {
        swap(a, b);
    }
    if (c > d)
    {
        swap(c, d);
    }
    return (a <= d && b >= c) || (c <= b && d >= a);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int z1 = ccw(x1, y1, x2, y2, x3, y3);
    int z2 = ccw(x1, y1, x2, y2, x4, y4);
    int z3 = ccw(x3, y3, x4, y4, x1, y1);
    int z4 = ccw(x3, y3, x4, y4, x2, y2);

    if (z1 * z2 == 0 && z3 * z4 == 0) {
        cout << (isLine(x1, x2, x3, x4) && isLine(y1, y2, y3, y4));
    }
    else {
        cout << (z1 * z2 <= 0 && z3 * z4 <= 0);
    }
}