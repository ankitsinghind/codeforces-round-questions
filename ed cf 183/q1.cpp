#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        int left = n % 3;
        int adds = (3 - left) % 3;
        cout << adds << "\n";
    }
    return 0;
}