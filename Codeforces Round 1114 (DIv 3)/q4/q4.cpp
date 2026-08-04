#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<int> e_a, o_a;
    vector<int> e_b, o_b;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (a[i] == '1')
                e_a.push_back(i);
            if (b[i] == '1')
                e_b.push_back(i);
        }
        else
        {
            if (a[i] == '1')
                o_a.push_back(i);
            if (b[i] == '1')
                o_b.push_back(i);
        }
    }

    if (e_a.size() != e_b.size() || o_a.size() != o_b.size())
    {
        cout << -1 << "\n";
        return;
    }

    long long ans = 0;

    for (size_t i = 0; i < e_a.size(); i++)
    {
        int diff = e_a[i] - e_b[i];
        ans += (diff < 0 ? -diff : diff) / 2;
    }

    for (size_t i = 0; i < o_a.size(); i++)
    {
        int diff = o_a[i] - o_b[i];
        ans += (diff < 0 ? -diff : diff) / 2;
    }

    cout << ans << "\n";
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}
