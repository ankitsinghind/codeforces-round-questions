#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (auto &x : a)
            cin >> x;

        long long m = *min_element(a.begin(), a.end());

        long long min_dif = LLONG_MAX;

        for (auto x : a)
        {
            if (x != m)
            {
                min_dif = min(min_dif, x - m);
            }
        }

        cout << max(m, min_dif) << "\n";
    }
    return 0;
}
