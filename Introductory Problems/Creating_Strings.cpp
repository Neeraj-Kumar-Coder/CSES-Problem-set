#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector<string> permutations;
    do
        permutations.push_back(s);
    while (next_permutation(s.begin(), s.end()));

    cout << permutations.size() << '\n';
    for (auto &&perm : permutations)
        cout << perm << '\n';

    return 0;
}