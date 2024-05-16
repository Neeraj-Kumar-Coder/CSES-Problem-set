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

    int n;
    cin >> n;

    vector<int> cube(n);
    cin >> cube;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        auto it = mp.upper_bound(cube[i]);

        if (it != mp.end())
        {
            if (it->second == 1)
                mp.erase(it);
            else
                --it->second;
        }

        mp[cube[i]]++;
    }

    int total = 0;
    for (auto &&[size, freq] : mp)
        total += freq;

    cout << total;

    return 0;
}