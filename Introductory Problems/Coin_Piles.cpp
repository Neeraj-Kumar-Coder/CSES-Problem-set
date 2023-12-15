#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (2 * a >= b && 2 * b >= a && (2 * b - a) % 3 == 0 && (2 * a - b) % 3 == 0)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}