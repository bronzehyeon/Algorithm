#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numer1, denomi1;
    cin >> numer1 >> denomi1;
    int numer2, denomi2;
    cin >> numer2 >> denomi2;

    int denomi = denomi1 * denomi2;
    int numer = numer1 * denomi2 + numer2 * denomi1;

    cout << numer / gcd(numer, denomi) << " " << denomi / gcd(numer, denomi);

    return 0;
}