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

    int count = 1;
    for (int i = 1; i < n; i++)
        if (arr[i - 1] != arr[i])
            ++count;

    cout << count;
    return 0;
}