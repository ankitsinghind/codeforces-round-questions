#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a;
    cin >> t;
    while (t--)
    {
        cin >> n;

        vector<int> a(n);
        int negatives = 0, zeros = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] == -1)
            {
                negatives++;
            }
            else if (a[i] == 0)
            {
                zeros++;
            }
        }

        int result;

        if (negatives % 2 == 1)
        {
            result = zeros + 2;
        }
        else
        {
            result = zeros;
        }

        cout << result << "\n";
    }
    return 0;
}