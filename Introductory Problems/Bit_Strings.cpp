#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    const int mod = 1e9 + 7;
    int count = 1, base = 2;
    while (n > 0)
    {
        if (n & 1)
            count = (count * base) % mod;

        base = (base * base) % mod;
        n >>= 1;
    }

    cout << count;
    return 0;
}