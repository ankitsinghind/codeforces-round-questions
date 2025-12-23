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

        vector<int> a(n);

        for (int &x : a)
        {
            cin >> x;
        }

        long long total = 0;

        for (int i = 0; i < n - 1; i++)
        {
            total += abs(a[i] - a[i + 1]);
        }

        long long answer = total;

        for (int k = 0; k < n; k++)
        {
            long long newtotal = total;
            if (k > 0)
            {
                newtotal -= abs(a[k] - a[k - 1]);
            }
            if (k < n - 1)
            {
                newtotal -= abs(a[k] - a[k + 1]);
            }
            if (k > 0 && k < n - 1)
            {
                newtotal += abs(a[k - 1] - a[k + 1]);
            }
            answer = min(answer, newtotal);
        }

        cout << answer << "\n";
    }
    return 0;
}
