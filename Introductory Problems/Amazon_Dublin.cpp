#include <bits/stdc++.h>

#define int long long int

using namespace std;

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

class Segment_Tree
{
private:
    vector<int> seg_tree;
    int arr_size;

    void updateUtil(int low, int high, int seg_index, int index, int value)
    {
        if (low == high)
        {
            seg_tree[seg_index] = value;
            return;
        }

        int mid = low + (high - low) / 2;
        if (index >= low && index <= mid)
            updateUtil(low, mid, 2 * seg_index + 1, index, value);
        else
            updateUtil(mid + 1, high, 2 * seg_index + 2, index, value);
        seg_tree[seg_index] = max(seg_tree[2 * seg_index + 1], seg_tree[2 * seg_index + 2]);
    }

    int queryUtil(int low, int high, int seg_index, int start, int end)
    {
        if (start <= low && end >= high)
        {
            return seg_tree[seg_index];
        }

        if (start > high || end < low)
        {
            return INT_MIN;
        }

        int mid = low + (high - low) / 2;
        int left = queryUtil(low, mid, 2 * seg_index + 1, start, end);
        int right = queryUtil(mid + 1, high, 2 * seg_index + 2, start, end);
        return max(left, right);
    }

public:
    Segment_Tree(const int n)
    {
        build(n);
    }

    void build(const int n)
    {
        arr_size = n;
        seg_tree.resize(4 * arr_size + 1, 0);
    }

    void update(int index, int value)
    {
        updateUtil(0, arr_size - 1, 0, index, value);
    }

    int query(int start, int end)
    {
        if (start > end)
            return LLONG_MIN;

        return queryUtil(0, arr_size - 1, 0, start, end);
    }
};

int helper(vector<int> &arr, int index, vector<int> &ngl)
{
    if (index == 0)
        return LLONG_MIN;

    if (index < 0)
        return 0;

    int answer = 0;
    for (int i = ngl[index]; i >= 0; i--)
        answer = max(answer, 1 + helper(arr, i - 1, ngl));

    return answer;
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

    stack<int> s;
    vector<int> ngl(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        ngl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    vector<int> dp(n, 0);
    Segment_Tree st(n);
    st.update(0, LLONG_MIN);

    for (int index = 1; index < n; index++)
    {
        if (ngl[index] == -1)
        {
            dp[index] = LLONG_MIN;
            st.update(index, LLONG_MIN);
            continue;
        }

        dp[index] = 1 + max(0LL, st.query(0, ngl[index] - 1));
        st.update(index, dp[index]);
    }

    cout << max(0LL, dp[n - 1]);
    return 0;
}