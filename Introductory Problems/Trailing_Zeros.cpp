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

    int trailingZeroes = 0, denom = 5;
    while (n / denom)
    {
        trailingZeroes += n / denom;
        denom *= 5;
    }

    cout << trailingZeroes;
    return 0;
}