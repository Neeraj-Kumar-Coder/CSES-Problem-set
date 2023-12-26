#include <bits/stdc++.h>

#define int long long int
#define GRID_SIZE 7

using namespace std;

bool visited[GRID_SIZE][GRID_SIZE];
const int change[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
string directions;
int n;

int backtrack(int x, int y, int index, char lastMove)
{
    if (x == GRID_SIZE - 1 && y == 0)
        return index == n;

    if (index == n)
        return 0;

    // Start [Grid Split Check]
    if ((((lastMove == '3' && (y + 1 >= GRID_SIZE || visited[x][y + 1])) || (lastMove == '1' && (y - 1 < 0 || visited[x][y - 1]))) && x - 1 >= 0 && !visited[x - 1][y] && x + 1 < GRID_SIZE && !visited[x + 1][y]) ||
        (((lastMove == '0' && (x - 1 < 0 || visited[x - 1][y])) || (lastMove == '2' && (x + 1 >= GRID_SIZE || visited[x + 1][y]))) && y - 1 >= 0 && !visited[x][y - 1] && y + 1 < GRID_SIZE && !visited[x][y + 1]))
        return 0;

    // End [Grid Split Check]

    visited[x][y] = true;

    if (directions[index] != '?')
    {
        int nx = x + change[directions[index] - '0'][0], ny = y + change[directions[index] - '0'][1];

        if (nx < 0 || ny < 0 || nx >= GRID_SIZE || ny >= GRID_SIZE || visited[nx][ny])
        {
            visited[x][y] = false;
            return 0;
        }

        int count = backtrack(nx, ny, index + 1, directions[index]);
        visited[x][y] = false;
        return count;
    }

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + change[i][0], ny = y + change[i][1];

        if (nx < 0 || ny < 0 || nx >= GRID_SIZE || ny >= GRID_SIZE || visited[nx][ny])
            continue;

        count += backtrack(nx, ny, index + 1, i + '0');
    }

    visited[x][y] = false;
    return count;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> directions;

    for (auto &&direction : directions)
    {
        switch (direction)
        {
        case 'U':
            direction = '0';
            break;
        case 'L':
            direction = '1';
            break;
        case 'D':
            direction = '2';
            break;
        case 'R':
            direction = '3';
            break;
        default:
            break;
        }
    }

    n = directions.length();
    cout << backtrack(0, 0, 0, '?');
    return 0;
}