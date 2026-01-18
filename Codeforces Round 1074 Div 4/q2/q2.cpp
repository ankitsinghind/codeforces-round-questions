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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        auto value = [&](vector<int> &arr)
        {
            long long sum = 0;
            int current_max = INT_MIN;
            for (int x : arr)
            {
                current_max = max(current_max, x);
                sum += current_max;
            }
            return sum;
        };

        long long max_val = value(a);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(a[i], a[j]);
                max_val = max(max_val, value(a));
                swap(a[i], a[j]);
            }
        }

        cout << max_val << "\n";
    }
    return 0;
}
