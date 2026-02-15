#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
    {
        return;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    const int INF = 1e9;
    vector<int> dp(7, 0);

    for (int v = 1; v <= 6; ++v)
    {
        dp[v] = (a[0] == v ? 0 : 1);
    }

    for (int i = 1; i < n; ++i)
    {
        vector<int> next_dp(7, INF);
        for (int v = 1; v <= 6; ++v)
        {
            int cost = (a[i] == v ? 0 : 1);
            int min_prev = INF;
            for (int k = 1; k <= 6; ++k)
            {
                if (k != v && k + v != 7)
                {
                    min_prev = min(min_prev, dp[k]);
                }
            }
            next_dp[v] = cost + min_prev;
        }
        dp = next_dp;
    }

    int result = INF;
    for (int v = 1; v <= 6; ++v)
    {
        result = min(result, dp[v]);
    }
    cout << result << "\n";
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
