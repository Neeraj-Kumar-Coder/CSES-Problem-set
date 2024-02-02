#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (auto &&ele : p)
        cin >> ele;

    sort(p.begin(), p.end());

    int low = 0, high = n - 1, count = 0;
    while (low <= high)
    {
        if (p[low] + p[high] <= x)
            ++low, --high;
        else
            --high;
        ++count;
    }

    cout << count;
    return 0;
}