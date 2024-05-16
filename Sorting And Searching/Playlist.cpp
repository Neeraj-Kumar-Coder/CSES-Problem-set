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

    vector<int> arr(n);
    cin >> arr;

    set<int> s;
    int low = 0, high = 0, maxx = 0;
    while (high < n)
    {
        if (!s.count(arr[high]))
        {
            s.insert(arr[high++]);
            maxx = MAX(maxx, s.size());
        }
        else
            s.erase(arr[low++]);
    }

    cout << maxx;
    return 0;
}