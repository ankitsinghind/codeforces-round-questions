#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int64> f(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> f[i];

        // Step 1: compute total sum T
        int64 T = (f[1] + f[n]) / (n - 1);

        // Step 2: compute prefix sums S_x
        vector<int64> S(n, 0);
        for (int x = 1; x <= n - 1; x++)
        {
            S[x] = (f[x + 1] - f[x] + T) / 2;
        }

        // Step 3: recover a_i
        vector<int64> a(n + 1);
        a[1] = S[1];
        for (int i = 2; i <= n - 1; i++)
        {
            a[i] = S[i] - S[i - 1];
        }
        a[n] = T - S[n - 1];

        // Output
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
