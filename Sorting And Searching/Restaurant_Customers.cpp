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

    vector<pair<int, int>> customers(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i].first >> customers[i].second;
        s.insert(customers[i].first);
        s.insert(customers[i].second);
    }

    vector<int> collection;
    unordered_map<int, int> indexOf;
    for (auto &&e : s)
        indexOf[e] = collection.size(), collection.push_back(e);

    int m = collection.size();
    vector<int> counter(m, 0);

    for (auto &&[s, e] : customers)
    {
        counter[indexOf[s]]++;
        if (indexOf[e] + 1 < m)
            counter[indexOf[e] + 1]--;
    }

    for (int i = 1; i < m; i++)
        counter[i] += counter[i - 1];

    cout << *max_element(counter.begin(), counter.end());
    return 0;
}