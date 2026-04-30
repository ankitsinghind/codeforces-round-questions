#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;

        if (x % 2 == 0 && y % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (x % 2 != 0 && y % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
