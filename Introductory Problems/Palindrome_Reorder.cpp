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

    int freq[26] = {0}, oddFreqs = 0;
    for (auto &&ch : s)
        if ((++freq[ch - 'A']) & 1)
            ++oddFreqs;
        else
            --oddFreqs;

    if (oddFreqs > 1)
        cout << "NO SOLUTION";
    else
    {
        char oddChar = '#';
        int low = 0, high = s.length() - 1;
        for (int i = 0; i < 26; i++)
        {
            while (freq[i] > 1)
            {
                s[low++] = s[high--] = 'A' + i;
                freq[i] -= 2;
            }

            if (freq[i] & 1)
                oddChar = 'A' + i;
        }

        if (low == high)
            s[low] = oddChar;

        cout << s;
    }
    return 0;
}