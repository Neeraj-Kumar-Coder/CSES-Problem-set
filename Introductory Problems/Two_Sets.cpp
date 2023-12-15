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

    if ((n * (n + 1) / 2) & 1)
        cout << "NO";
    else
    {
        cout << "YES\n";

        vector<int> part1, part2;
        for (int i = n, sum = 0; i >= 1; i--)
            if (sum + i <= n * (n + 1) / 4)
                sum += i, part1.push_back(i);
            else
                part2.push_back(i);

        cout << part1.size() << '\n';
        for (auto &&ele : part1)
            cout << ele << ' ';

        cout << '\n';

        cout << part2.size() << '\n';
        for (auto &&ele : part2)
            cout << ele << ' ';
    }
    return 0;
}