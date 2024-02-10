#include <bits/stdc++.h>

#define int long long int

using namespace std;

int binSearch(vector<pair<int, int>> &arr, int value, int start)
{
    int low = start, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid].first == value)
            return mid;

        if (arr[mid].first < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr.size();
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n && arr[i].first <= x; i++)
    {
        int idx1 = arr[i].second;
        int idx2 = binSearch(arr, x - arr[i].first, i + 1);

        if (idx2 == n)
            continue;

        idx2 = arr[idx2].second;

        cout << idx1 + 1 << ' ' << idx2 + 1;
        return 0;
    }

    cout << "IMPOSSIBLE";
    return 0;
}