#include <bits/stdc++.h>
using namespace std;

int maxApples(const vector<int> &b)
{
    int n = b.size();
    vector<int> extended(2 * n);

    for (int i = 0; i < 2 * n; ++i)
    {
        extended[i] = b[i % n];
    }

    vector<int> dp(2 * n, 1);
    int maxEat = 1;

    for (int i = 1; i < 2 * n; ++i)
    {
        for (int j = max(0, i - n); j < i; ++j)
        {
            if (extended[i] > extended[j])
            {

                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxEat = max(maxEat, dp[i]);
    }

    return min(maxEat, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        cout << maxApples(b) << "\n";
    }
    return 0;
}
