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

    int temp = 0, current_sum = 0, max_sum = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        current_sum = max(current_sum + temp, temp);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum;
    return 0;
}