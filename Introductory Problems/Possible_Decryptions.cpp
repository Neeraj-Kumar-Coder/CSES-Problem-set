#include <bits/stdc++.h>

#define int long long int
#define MOD 1000000007

using namespace std;

vector<int> operations(438, 0);
int dp[438][2][2][438];

int digitDP(const string &num1, const string &num2, int index, int largeThanNum1, int smallThanNum2, int ones, const int k)
{
    int n = num1.length();

    if (index == n)
        return operations[ones] == k;

    if (dp[index][largeThanNum1][smallThanNum2][ones] != -1)
        return dp[index][largeThanNum1][smallThanNum2][ones];

    int start = num1[index] - '0', end = num2[index] - '0';

    if (largeThanNum1)
        start = 0;

    if (smallThanNum2)
        end = 1;

    int answer = 0;
    for (int digit = start; digit <= end; digit++)
    {
        answer += digitDP(num1, num2, index + 1, largeThanNum1 || (digit > num1[index] - '0'), smallThanNum2 || (digit < num2[index] - '0'), ones + digit, k);
        answer %= MOD;
    }

    return dp[index][largeThanNum1][smallThanNum2][ones] = answer;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    operations[0] = -1;
    operations[1] = 1;
    for (int i = 2; i <= 437; i++)
        operations[i] = operations[__builtin_popcount(i)] + 1;

    string high;
    int k;
    cin >> high >> k;

    string low(high.length(), '0');

    memset(dp, -1, sizeof(dp));

    int answer = digitDP(low, high, 0, 0, 0, 0, k);

    if (k == 1)
        answer = (answer - 1 + MOD) % MOD;

    cout << answer << '\n';

    // Brute
    int number = 0, n = high.length();
    for (int i = 0; i < n; i++)
        number |= (high[i] - '0') << (n - 1 - i);

    int total = 0;
    for (int i = 1; i <= number; i++)
    {
        int ops = 0, t = i;
        while (t != 1)
        {
            ops++;
            t = __builtin_popcount(t);
        }

        if (ops == k)
            total++;
    }

    cout << total;
    return 0;
}