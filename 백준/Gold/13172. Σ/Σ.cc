#include <iostream>
using namespace std;
#define ll long long
int M;
ll N, S;
ll mod = 1000000007;

ll gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

ll pow(ll a, ll b) {
	if (b == 1) return a;
	if (b % 2 == 1) return a * pow(a, b - 1) % mod;
	ll p = pow(a, b / 2);
	return p * p % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	ll ans = 0;

	while (M--) {
		cin >> N >> S;

		ll g = gcd(N, S);
		ll n = N / g;
		ll s = S / g;

		ans += s * pow(n, mod - 2) % mod;
		ans %= mod;
	}

	cout << ans;
}

