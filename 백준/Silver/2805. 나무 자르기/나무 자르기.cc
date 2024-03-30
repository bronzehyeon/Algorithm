#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> v;

long answer = 0;

long N, M;

void solve(long s, long e)
{
    if (s > e)
        return;
    long mid = (s + e) / 2;
    long count = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (mid > v[i])
        {
            break;
        }
        count += v[i] - mid;
    }
    if (count >= M)
    {
        if (answer < mid)
        {
            answer = mid;
        }
        solve(mid + 1, e);
    }
    if (count < M)
    {
        solve(s, mid - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    long max = 0;

    for (int i = 0; i < N; i++)
    {
        long tmp;
        cin >> tmp;

        if (tmp > max)
        {
            max = tmp;
        }

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    solve(1, max);

    cout << answer;
}