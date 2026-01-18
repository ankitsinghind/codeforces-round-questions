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

        for (int i = 1; i <= n; i++)
        {
            cout << i;
            if (i < n)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
