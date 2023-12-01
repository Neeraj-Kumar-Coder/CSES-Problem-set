#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string dna;
    cin >> dna;

    int maxLength = 0, currentLength = 0;
    char currentCharacter = '#';

    for (auto &&ch : dna)
    {
        if (ch == currentCharacter)
            ++currentLength;
        else
        {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
            currentCharacter = ch;
        }
    }

    cout << (maxLength = max(maxLength, currentLength));
    return 0;
}