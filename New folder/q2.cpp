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

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        int maximum_difference = 0;

        for (int i = 0; i < n; i += 2)
        {
            int difference = abs(a[i] - a[i + 1]);
            maximum_difference = max(maximum_difference, difference);
        }

        cout << maximum_difference << "\n";
    }
    return 0;
}
