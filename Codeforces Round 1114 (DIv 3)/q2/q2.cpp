#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void run()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int base = 1;
    for (int j = 1; j < n; ++j)
    {
        if (s[j] != s[j - 1])
            base++;
    }

    int best = base;

    for (int i = 1; i < n - 1; ++i)
    {
        int delta = 0;

        if (s[i] != s[i - 1])
            delta--;
        if (s[i] != s[i + 1])
            delta--;
        if (s[i - 1] != s[i + 1])
            delta++;

        best = min(best, base + delta);
    }

    cout << best << "\n";
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            run();
        }
    }
    return 0;
}
