#include <bits/stdc++.h>

#define int long long int

using namespace std;

int column[8], leftDiagonal[15], rightDiagonal[15];

/*
00 01 02 03 04 05 06 07
10 11 12 13 14 15 16 17
20 21 22 23 24 25 26 27
30 31 32 33 34 35 36 37
40 41 42 43 44 45 46 47
50 51 52 53 54 55 56 57
60 61 62 63 64 65 66 67
70 71 72 73 74 75 76 77
*/

int backtrack(vector<string> &chess, int row)
{
    if (row == 8)
        return 1;

    int count = 0;
    for (int col = 0; col < 8; col++)
    {
        if (column[col] || leftDiagonal[row - col + 7] || rightDiagonal[row + col] || chess[row][col] == '*')
            continue;

        column[col] = leftDiagonal[row - col + 7] = rightDiagonal[row + col] = 1;
        count += backtrack(chess, row + 1);
        column[col] = leftDiagonal[row - col + 7] = rightDiagonal[row + col] = 0;
    }

    return count;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> chess(8);
    for (int i = 0; i < 8; i++)
        cin >> chess[i];

    memset(column, 0, sizeof(column));
    memset(leftDiagonal, 0, sizeof(leftDiagonal));
    memset(rightDiagonal, 0, sizeof(rightDiagonal));

    cout << backtrack(chess, 0);
    return 0;
}