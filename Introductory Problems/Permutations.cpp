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

    if (n >= 2 && n <= 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    vector<int> permutation(n);

    int i = 0;
    for (int start = 2; i < n && start <= n; i++, start += 2)
        permutation[i] = start;

    for (int start = 1; i < n && start <= n; i++, start += 2)
        permutation[i] = start;

    for (int i = 0; i < n; i++)
        cout << permutation[i] << ' ';

    return 0;
}