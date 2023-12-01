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

    int previous = 0, current, operations = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> current;
        operations += max(0LL, previous - current);
        previous = max(previous, current);
    }

    cout << operations;
    return 0;
}