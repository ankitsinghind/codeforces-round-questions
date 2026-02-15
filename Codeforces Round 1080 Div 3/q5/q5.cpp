#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

struct Node
{
    int L, R;
    int p;
    long long sz;
    long long t;
};

void solve()
{
    int n;
    if (!(cin >> n))
    {
        return;
    }
    vector<Node> nodes(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> nodes[i].L >> nodes[i].R;
        nodes[i].p = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (nodes[i].L)
        {
            nodes[nodes[i].L].p = i;
        }
        if (nodes[i].R)
        {
            nodes[nodes[i].R].p = i;
        }
    }
    vector<int> order;
    vector<int> st;

    st.push_back(1);

    while (!st.empty())
    {
        int u = st.back();
        st.pop_back();
        order.push_back(u);
        if (nodes[u].L)
        {
            st.push_back(nodes[u].L);
        }
        if (nodes[u].R)
        {
            st.push_back(nodes[u].R);
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        int u = order[i];
        nodes[u].sz = 1;
        if (nodes[u].L)
        {
            nodes[u].sz += nodes[nodes[u].L].sz;
        }
        if (nodes[u].R)
        {
            nodes[u].sz += nodes[nodes[u].R].sz;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int u = order[i];
        long long s_u = (2 * nodes[u].sz - 1) % MOD;
        if (nodes[u].p == 0)
        {
            nodes[u].t = s_u;
        }
        else
        {
            nodes[u].t = (s_u + nodes[nodes[u].p].t) % MOD;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << nodes[i].t << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
    {
        return 0;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}
