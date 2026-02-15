#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Function
{
    long long a, b, c;
};

bool is_strictly_greater(const Function &f1, const Function &f2)
{
    long long A = f1.a - f2.a;
    long long B = f1.b - f2.b;
    long long C = f1.c - f2.c;
    if (A == 0)
    {
        return (B == 0 && C > 0);
    }
    if (A > 0)
    {
        return (B * B < 4 * A * C);
    }
    return false;
}

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vector<Function> f(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i].a >> f[i].b >> f[i].c;
    }
    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            if (is_strictly_greater(f[i], f[j]))
            {
                adj[i].push_back(j);
                in_degree[j]++;
            }
        }
    }
    vector<int> topo;
    vector<int> q;
    vector<int> current_in_degree = in_degree;
    for (int i = 0; i < n; ++i)
    {
        if (current_in_degree[i] == 0)
            q.push_back(i);
    }
    int head = 0;
    while (head < q.size())
    {
        int u = q[head++];
        topo.push_back(u);
        for (int v : adj[u])
        {
            if (--current_in_degree[v] == 0)
                q.push_back(v);
        }
    }
    vector<int> dp_up(n, 1);
    for (int u : topo)
    {
        for (int v : adj[u])
        {
            dp_up[v] = max(dp_up[v], dp_up[u] + 1);
        }
    }
    vector<int> dp_down(n, 1);
    for (int i = n - 1; i >= 0; --i)
    {
        int u = topo[i];
        for (int v : adj[u])
        {
            dp_down[u] = max(dp_down[u], dp_down[v] + 1);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << dp_up[i] + dp_down[i] - 1 << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}
