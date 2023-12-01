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

    while (n != 1)
    {
        cout << n << ' ';
        if (n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }

    cout << n;
    return 0;
}