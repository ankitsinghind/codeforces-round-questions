#include <iostream>
using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    int blocks_x = n;
    int blocks_y = (3 * n) / 2;
    long long total = (long long)blocks_x * blocks_y * 2;
    cout << total << "\n";

    for (int i = 0; i < blocks_x; ++i)
    {
        int x0 = 3 * i + 1;
        for (int j = 0; j < blocks_y; ++j)
        {
            int y0 = 2 * j + 1;
            cout << x0 << " " << y0 << " "
                 << x0 << " " << y0 + 1 << " "
                 << x0 + 1 << " " << y0 << "\n";
            cout << x0 + 1 << " " << y0 + 1 << " "
                 << x0 + 2 << " " << y0 + 1 << " "
                 << x0 + 2 << " " << y0 << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}
