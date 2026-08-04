#include <iostream>
#include <string>

using namespace std;

void check()
{
    int n;
    cin >> n;
    string u, v;
    cin >> u >> v;

    if (u == v)
    {
        cout << "YES\n";
        return;
    }

    int u_even1 = 0, u_odd1 = 0;
    int v_even1 = 0, v_odd1 = 0;

    int u_total0 = 0, v_total0 = 0;

    for (int i = 0; i < n; ++i)
    {
        if (u[i] == '0')
            u_total0++;
        if (v[i] == '0')
            v_total0++;

        if (i % 2 == 0)
        {
            if (u[i] == '1')
                u_even1++;
            if (v[i] == '1')
                v_even1++;
        }
        else
        {
            if (u[i] == '1')
                u_odd1++;
            if (v[i] == '1')
                v_odd1++;
        }
    }

    if (u_total0 != v_total0)
    {
        cout << "NO\n";
        return;
    }

    if (u_even1 == v_even1 && u_odd1 == v_odd1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            check();
        }
    }
    return 0;
}
