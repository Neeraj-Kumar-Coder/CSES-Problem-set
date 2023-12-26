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

    vector<int> apples(n);
    for (auto &&apple : apples)
        cin >> apple;

    int answer = LLONG_MAX;
    for (int mask = 0; mask < (1LL << n); mask++)
    {
        int left = 0, right = 0;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                left += apples[i];
            else
                right += apples[i];

        answer = min(answer, llabs(left - right));
    }

    cout << answer;
    return 0;
}