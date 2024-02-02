#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> h(n), t(m);
    for (auto &&e : h)
        cin >> e;
    for (auto &&e : t)
        cin >> e;

    map<int, int> mp;
    for (auto &&e : h)
        mp[e]++;

    for (auto &&e : t)
    {
        auto it = mp.upper_bound(e);
        if (it == mp.begin())
        {
            cout << -1 << '\n';
            continue;
        }

        --it;
        cout << it->first << '\n';
        if (--it->second == 0)
            mp.erase(it);
    }
    return 0;
}