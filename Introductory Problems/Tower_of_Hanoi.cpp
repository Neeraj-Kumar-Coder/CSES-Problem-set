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

    vector<pair<int, int>> moves;

    function<void(int, int, int, int)> towerOfHanoi = [&](int from, int help, int to, int count)
    {
        if (count == 0)
            return;

        towerOfHanoi(from, to, help, count - 1);
        moves.emplace_back(from, to);
        towerOfHanoi(help, from, to, count - 1);
    };

    towerOfHanoi(1, 2, 3, n);

    cout << moves.size() << '\n';
    for (auto &&[from, to] : moves)
        cout << from << ' ' << to << '\n';

    return 0;
}