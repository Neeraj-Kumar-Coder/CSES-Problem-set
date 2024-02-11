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

    vector<int> coins(n);
    for (auto &&coin : coins)
        cin >> coin;

    sort(coins.begin(), coins.end());
    int madeTill = 0;

    for (auto &&coin : coins)
    {
        if (coin <= madeTill + 1)
            madeTill += coin;
        else
            break;
    }

    cout << madeTill + 1;
    return 0;
}