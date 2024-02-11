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

    vector<int> arr(n);
    for (auto &&ele : arr)
        cin >> ele;

    sort(arr.begin(), arr.end());
    int total = accumulate(arr.begin(), arr.end(), 0LL), prefix = 0, prefixCount = 0, minCost = LLONG_MAX;

    for (auto &&ele : arr)
    {
        ++prefixCount;
        prefix += ele;

        int tempCost = prefixCount * ele - prefix + (total - prefix) - (n - prefixCount) * ele;
        minCost = min(minCost, tempCost);
    }

    cout << minCost;
    return 0;
}