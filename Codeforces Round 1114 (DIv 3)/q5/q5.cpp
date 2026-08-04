#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long> b(n);
    map<long long, vector<int>> groups;

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        groups[b[i]].push_back(i);
    }

    if (groups.find(0) == groups.end())
    {
        cout << -1 << "\n";
        return;
    }

    vector<long long> a(n, 0);
    vector<long long> shadow_vals;

    for (auto &p : groups)
    {
        shadow_vals.push_back(p.first);
    }

    int m = shadow_vals.size();
    vector<long long> val(m, 0);

    long long count_0 = groups[0].size();
    if (m == 1)
    {
        val[0] = 1;
    }
    else
    {
        long long b_next = shadow_vals[1];
        if (b_next % count_0 != 0)
        {
            cout << -1 << "\n";
            return;
        }
        val[0] = b_next / count_0;
        if (val[0] < 1)
        {
            cout << -1 << "\n";
            return;
        }
    }

    long long sum_so_far = count_0 * val[0];

    for (int i = 1; i < m; i++)
    {
        if (shadow_vals[i] != sum_so_far)
        {
            cout << -1 << "\n";
            return;
        }

        long long count_i = groups[shadow_vals[i]].size();

        if (i + 1 < m)
        {
            long long b_next = shadow_vals[i + 1];
            long long rem = b_next - sum_so_far;
            if (rem <= 0 || rem % count_i != 0)
            {
                cout << -1 << "\n";
                return;
            }
            val[i] = rem / count_i;
            if (val[i] <= val[i - 1])
            {
                cout << -1 << "\n";
                return;
            }
        }
        else
        {
            val[i] = val[i - 1] + 1;
        }

        sum_so_far += count_i * val[i];
    }

    for (int i = 0; i < m; i++)
    {
        for (int idx : groups[shadow_vals[i]])
        {
            a[idx] = val[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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
