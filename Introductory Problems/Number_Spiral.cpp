#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, r, c;
    cin >> t;

    while (t--)
    {
        cin >> r >> c;
        int start = 1 + (max(r, c) - 1) * (max(r, c) - 1);

        if (max(r, c) & 1)
            cout << (start + max(r, c) - r + c - 1);
        else
            cout << (start + r - 1 + max(r, c) - c);

        cout << '\n';
    }
    return 0;
}