#include <bits/stdc++.h>

#define int long long int

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    function<int(int, int)> binExpo = [&](int base, int exp)
    {
        int answer = 1;
        while (exp > 0)
        {
            if (exp & 1)
                answer *= base;
            base *= base;
            exp >>= 1;
        }
        return answer;
    };

    while (q--)
    {
        int k;
        cin >> k;

        int digit = 1;
        while (k >= digit * 9 * binExpo(10, digit - 1))
            k -= digit * 9 * binExpo(10, digit - 1), digit++;

        if (k == 0)
            cout << 9;
        else
        {
            int num = binExpo(10, digit - 1) + k / digit - 1;
            int remain = k % digit;

            if (remain)
                num++;
            else
                remain = digit;

            string number = to_string(num);

            cout << number[remain - 1];
        }

        cout << '\n';
    }
    return 0;
}