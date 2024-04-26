#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N;
    cin >> N;

    int a, b, c, d, e, f;

    cin >> a >> b >> c >> d >> e >> f;

    long long answer = 0;
    if (N > 1) {
        answer += min({ a,b,c,d,e,f }) * ((N -2) * (N - 2) * 5 + (N - 2) * 4);
        answer += min({a + b + c , a + b + d, a + d + e, a + e + c, f + b + c, f + b + d, f + d + e, f + e + c }) * 4;//위쪽에 보여질 4개의 꼭짓점
        answer += min({ a + b, a + c, a + d, a + e, f + b, f + c, f + d, f + e, d + e, d + b, c + e, c + b }) * (4 + (N - 2) * 8);
    }
    else {
        answer += a + b + c + d + e + f - max({ a,b,c,d,e,f });
    }
    cout << answer;
}

