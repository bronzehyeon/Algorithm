#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int x, y;
    for (int i = -999; i <= 999; i++) {
        if (b == 0) {
            cout << c / a << " " << (f - c * d / a) / e; 
            break;
        }
        else {
            x = i;
            y = (c - a * i) / b + (c - a * i) % b;
            if (d * x + e * y == f) {
                cout << x << " " << y;
            }
        }
       
    }
}
