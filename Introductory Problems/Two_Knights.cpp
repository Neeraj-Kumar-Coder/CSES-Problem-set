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

    for (int k = 1; k <= n; k++)
    {
        if (k == 1)
            cout << 0;
        else if (k == 2)
            cout << 6;
        else if (k == 3)
            cout << 28;
        else
        {
            int ksq = k * k;
            int total = ksq * (ksq - 1) / 2;
            int invalid = (8 * max(0LL, k - 4) * max(0LL, k - 4) + 24 * max(0LL, k - 4) + 4 * (4 * max(0LL, k - 4) + 4) + 32) / 2;
            cout << total - invalid;
        }
        cout << '\n';
    }

    return 0;
}