#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n, k;
        cin >> n >> k;

        queue<pair<long long, int>> q;
        unordered_set<long long> visit;

        q.push({n, 0});
        visit.insert(n);

        int time = -1;
        while (!q.empty())
        {
            pair<long long, int> p = q.front();
            q.pop();

            long long x = p.first;
            int steps = p.second;

            if (x == k)
            {
                time = steps;
                break;
            }
            if (x < k)
            {
                continue;
            }

            long long a = x / 2;
            long long b = (x + 1) / 2;

            if (!visit.count(a))
            {
                q.push({a, steps + 1});
                visit.insert(a);
            }
            if (!visit.count(b))
            {
                q.push({b, steps + 1});
                visit.insert(b);
            }
        }

        cout << time << "\n";
    }
    return 0;
}
