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

    int totalSum = n * (n + 1) / 2, temp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        totalSum -= temp;
    }

    cout << totalSum;
    return 0;
}