#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        int max_val = 1;
        int current = 1;

        for (int i = 1; i < (int)a.size(); i++)
        {
            if (a[i] == a[i - 1] + 1)
            {
                current++;
            }
            else
            {
                current = 1;
            }
            max_val = max(max_val, current);
        }

        cout << max_val << "\n";
    }
    return 0;
}
