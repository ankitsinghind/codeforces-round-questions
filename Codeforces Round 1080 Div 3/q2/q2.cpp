#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<vector<int>> adj(n + 1);

        for (int i = 1; i <= n / 2; i++)
        {
            adj[i].push_back(2 * i);
            adj[2 * i].push_back(i);
        }

        vector<bool> visited(n + 1, false);
        bool ok = true;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                vector<int> comp;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    comp.push_back(u);
                    for (int v : adj[u])
                    {
                        if (!visited[v])
                        {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }

                vector<int> vals;
                for (int index : comp)
                    vals.push_back(a[index]);
                sort(vals.begin(), vals.end());

                vector<int> target;
                for (int index : comp)
                    target.push_back(index);
                sort(target.begin(), target.end());

                if (vals != target)
                {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
