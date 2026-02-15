#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 300005;
const int MAXP = 20;

struct Node
{
    int L, R, p;
    long long sz, s;
};

Node nodes[MAXN];
int up[MAXN][MAXP];
long long ssum[MAXN][MAXP];
int first_idx[MAXN];
vector<int> seq;

void solve()
{
    int n, q;
    if (!(cin >> n >> q))
        return;

    for (int i = 0; i <= n; ++i)
    {
        nodes[i] = {0, 0, 0, 0, 0};
        for (int p = 0; p < MAXP; ++p)
        {
            up[i][p] = 0;
            ssum[i][p] = 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> nodes[i].L >> nodes[i].R;
    }

    nodes[1].p = 0;
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

    vector<int> tour_order;
    vector<int> st_ord;
    st_ord.push_back(1);
    while (!st_ord.empty())
    {
        int u = st_ord.back();
        st_ord.pop_back();
        tour_order.push_back(u);

        if (nodes[u].L)
        {
            st_ord.push_back(nodes[u].L);
        }
        if (nodes[u].R)
        {
            st_ord.push_back(nodes[u].R);
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        int u = tour_order[i];
        nodes[u].sz = 1;
        if (nodes[u].L)
        {
            nodes[u].sz += nodes[nodes[u].L].sz;
        }
        if (nodes[u].R)
            nodes[u].sz += nodes[nodes[u].R].sz;
        {
            nodes[u].s = 2 * nodes[u].sz - 1;
        }
    }

    seq.clear();
    struct State
    {
        int u;
        int step;
    };
    vector<State> st;

    st.push_back({1, 0});

    while (!st.empty())
    {
        State &cur = st.back();
        if (cur.step == 0)
        {
            first_idx[cur.u] = seq.size();
            seq.push_back(cur.u);
            cur.step = 1;
            if (nodes[cur.u].L)
                st.push_back({nodes[cur.u].L, 0});
        }
        else if (cur.step == 1)
        {
            if (nodes[cur.u].L)
                seq.push_back(cur.u);
            cur.step = 2;
            if (nodes[cur.u].R)
                st.push_back({nodes[cur.u].R, 0});
        }
        else if (cur.step == 2)
        {
            if (nodes[cur.u].R)
                seq.push_back(cur.u);
            st.pop_back();
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        up[i][0] = nodes[i].p;
        ssum[i][0] = nodes[i].s;
    }

    for (int p = 1; p < MAXP; ++p)
    {
        for (int i = 1; i <= n; ++i)
        {
            int mid = up[i][p - 1];
            if (mid != 0)
            {
                up[i][p] = up[mid][p - 1];
                ssum[i][p] = ssum[i][p - 1] + ssum[mid][p - 1];
            }
        }
    }

    for (int j = 0; j < q; ++j)
    {
        int v;
        long long k;
        cin >> v >> k;
        int u = v;
        for (int p = MAXP - 1; p >= 0; --p)
        {
            if (up[u][p] != 0 && ssum[u][p] <= k)
            {
                k -= ssum[u][p];
                u = up[u][p];
            }
        }
        cout << seq[first_idx[u] + k] << (j == q - 1 ? "" : " ");
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
