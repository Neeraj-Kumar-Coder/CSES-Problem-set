#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define ALL(iterable) (iterable).begin(), (iterable).end()
#define RALL(iterable) (iterable).rbegin(), (iterable).rend()
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ROUND(x) (((x) >= 0) ? (ll)((x) + 0.5) : (ll)((x) - 0.5))
#define DEBUG(...)                         \
    cout << "[DEBUG-" << __LINE__ << "]:"; \
    debug_cout(__VA_ARGS__);

short dx4[] = {-1, 0, 1, 0};
short dy4[] = {0, 1, 0, -1};

short dx8[] = {-1, -1, -1, 0, 1, 1, 1, 0};
short dy8[] = {-1, 0, 1, 1, 1, 0, -1, -1};

short kx[] = {2, 1, -1, -2, -2, -1, 1, 2};
short ky[] = {1, 2, 2, 1, -1, -2, -2, -1};

template <typename T>
void debug_cout(const T &arg)
{
    cout << " " << arg;
}

template <typename T, typename... Args>
void debug_cout(const T &firstArg, const Args &...args)
{
    cout << " " << firstArg;
    debug_cout(args...);
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p)
{
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> &vec)
{
    out << "[";
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin())
            out << ",";
        out << *it;
    }
    out << "]";
    return out;
}

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p)
{
    in >> p.first >> p.second;
    return in;
}

template <typename T>
istream &operator>>(istream &in, vector<T> &vec)
{
    for (auto &&v : vec)
        in >> v;
    return in;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x, n;
    cin >> x >> n;

    vector<ll> light(n);
    cin >> light;

    vector<ll> sortedLight = light;
    sort(ALL(sortedLight));

    map<ll, ll> indexOf;
    for (int i = 0; i < n; i++)
        indexOf[sortedLight[i]] = i;

    vector<ll> nearestLeftLight(n), nearestRightLight(n);

    nearestLeftLight[0] = -1;
    for (int i = 1; i < n; i++)
        nearestLeftLight[i] = i - 1;

    nearestRightLight[n - 1] = LLONG_MAX;
    for (int i = n - 2; i >= 0; i--)
        nearestRightLight[i] = i + 1;

    vector<ll> answer(n);
    ll maxx = MAX(sortedLight.front(), x - sortedLight.back());
    for (int i = 1; i < n; i++)
        maxx = MAX(maxx, sortedLight[i] - sortedLight[i - 1]);

    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] = maxx;

        int index = indexOf[light[i]];

        if (nearestLeftLight[index] != -1)
            nearestRightLight[nearestLeftLight[index]] = nearestRightLight[index];

        if (nearestRightLight[index] != LLONG_MAX)
            nearestLeftLight[nearestRightLight[index]] = nearestLeftLight[index];

        maxx = MAX(maxx, MIN(x, nearestRightLight[index] != LLONG_MAX ? sortedLight[nearestRightLight[index]] : LLONG_MAX) - MAX(0, nearestLeftLight[index] != -1 ? sortedLight[nearestLeftLight[index]] : -1));
    }

    for (auto &&ans : answer)
        cout << ans << ' ';

    return 0;
}