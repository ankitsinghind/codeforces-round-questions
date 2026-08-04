#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void check_transform()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int sa = 0, sb = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sa ^= a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sb ^= b[i];
    }

    vector<int> set_a(n + 1), set_b(n + 1);

    for (int i = 0; i < n; i++)
    {
        set_a[i] = a[i] ^ sa;
        set_b[i] = b[i] ^ sb;
    }
    set_a[n] = sa;
    set_b[n] = sb;

    sort(set_a.begin(), set_a.end());
    sort(set_b.begin(), set_b.end());

    if (set_a == set_b)
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
            check_transform();
        }
    }
    return 0;
}
