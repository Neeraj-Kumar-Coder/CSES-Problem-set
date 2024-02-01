#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (auto &&ele : a)
        cin >> ele;

    for (auto &&ele : b)
        cin >> ele;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (b[j] <= a[i])
        {
            if (a[i] - b[j] <= k)
                ++i, ++j, ++count;
            else
                ++j;
        }
        else
        {
            if (b[j] - a[i] <= k)
                ++i, ++j, ++count;
            else
                ++i;
        }
    }

    cout << count;
    return 0;
}