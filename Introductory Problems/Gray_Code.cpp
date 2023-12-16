#include <bits/stdc++.h>

#define int long long int

using namespace std;

vector<string> recurse(int n)
{
    if (n == 1)
        return {"0", "1"};

    vector<string> tmp = recurse(n - 1);
    vector<string> answer;
    int size = tmp.size();

    for (int i = 0; i < size; i++)
        answer.push_back(tmp[i] + "0");

    for (int i = size - 1; i >= 0; i--)
        answer.push_back(tmp[i] + "1");

    return answer;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> graycode = recurse(n);
    for (auto &&code : graycode)
        cout << code << '\n';
    return 0;
}