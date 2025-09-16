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
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        bool check = false;

        // Try all valid (l, r) pairs
        for (int l = 1; l < n - 1 && !check; ++l)
        {
            for (int r = l + 1; r < n && !check; ++r)
            {
                int sum1 = 0, sum2 = 0, sum3 = 0;

                // Calculate sums of the three parts
                for (int i = 0; i < l; ++i)
                    sum1 += arr[i];
                for (int i = l; i < r; ++i)
                    sum2 += arr[i];
                for (int i = r; i < n; ++i)
                    sum3 += arr[i];

                // Take modulo 3
                sum1 %= 3;
                sum2 %= 3;
                sum3 %= 3;

                // Check condition: all same or all different
                if ((sum1 == sum2 && sum2 == sum3) ||
                    (sum1 != sum2 && sum2 != sum3 && sum1 != sum3))
                {
                    cout << l << " " << r << "\n";
                    check = true;
                }
            }
        }

        if (!check)
        {
            cout << "0 0\n";
        }
    }

    return 0;
}
