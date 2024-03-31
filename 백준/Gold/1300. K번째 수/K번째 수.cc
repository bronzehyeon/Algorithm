#include<iostream>
#include<algorithm>
using namespace std;

long long N, K;
long long s, e, mid;
long long cnt;

long long count(long long mid)
{
	long long sum = 0;
	for (int i = 1; i <= N; i++) 
        sum += min(mid / i, N);
    
	return sum;
}

int main()
{
	cin >> N >> K;

	s = 1;
	e = N * N;

	while (s <= e)
	{
		mid = (s + e) / 2;

		cnt = count(mid);

		if (cnt >= K) e = mid - 1;
		else s = mid + 1;
	}
    
	cout << s;
}