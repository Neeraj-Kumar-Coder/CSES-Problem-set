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

    vector<pair<int, int>> movies(n);
    for (auto &&[s, e] : movies)
        cin >> s >> e;

    sort(movies.begin(), movies.end(), [](const pair<int, int> &left, const pair<int, int> &right)
         {
        if (left.second != right.second)
            return left.second < right.second;
        return left.first < right.first; });

    int end = -1, count = 0;
    for (auto &&[s, e] : movies)
    {
        if (s >= end)
        {
            ++count;
            end = e;
        }
    }

    cout << count;
    return 0;
}