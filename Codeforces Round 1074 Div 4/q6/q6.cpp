#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int winner;
    int xor_val;
    vector<int> order;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        int N = 1 << n;

        vector<unsigned long long> a(N);

        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }

        struct info
        {
            unsigned long long xor_val;
            int winner;
        };

        vector<info> seg(2 * N);

        for (int i = 0; i < N; i++)
        {
            seg[N + i] = {a[i], i};
        }

        for (int i = N - 1; i > 0; i--)
        {
            auto L = seg[i << 1];
            auto R = seg[i << 1 | 1];

            if (L.xor_val > R.xor_val || (L.xor_val == R.xor_val))
            {
                seg[i] = {L.xor_val ^ R.xor_val, L.winner};
            }
            else
            {
                seg[i] = {L.xor_val ^ R.xor_val, R.winner};
            }
        }

        while (q--)
        {
            int b;
            unsigned long long c;

            cin >> b >> c;
            b--;

            unsigned long long old = a[b];
            a[b] = c;

            int pos = N + b;
            seg[pos] = {a[b], b};
            for (pos >>= 1; pos; pos >>= 1)
            {
                auto L = seg[pos << 1];
                auto R = seg[pos << 1 | 1];
                if (L.xor_val > R.xor_val || (L.xor_val == R.xor_val))
                {
                    seg[pos] = {L.xor_val ^ R.xor_val, L.winner};
                }
                else
                {
                    seg[pos] = {L.xor_val ^ R.xor_val, R.winner};
                }
            }

            int above = 0;
            int idx = b;
            int node = N + b;

            while (node > 1)
            {
                int parent = node >> 1;
                int sibling = node ^ 1;
                auto L = seg[parent << 1];
                auto R = seg[parent << 1 | 1];
                bool left = (L.xor_val > R.xor_val || L.xor_val == R.xor_val);
                if (node == parent << 1)
                {
                    if (!left)
                    {
                        above += (1 << (__builtin_ctz(sibling)));
                    }
                }
                else
                {
                    if (left)
                    {
                        above += (1 << (__builtin_ctz(sibling)));
                    }
                }
                node = parent;
            }

            cout << above << "\n";

            a[b] = old;
            seg[N + b] = {a[b], b};
            for (pos = (N + b) >> 1; pos; pos >>= 1)
            {
                auto L = seg[pos << 1];
                auto R = seg[pos << 1 | 1];
                if (L.xor_val > R.xor_val || (L.xor_val == R.xor_val))
                {
                    seg[pos] = {L.xor_val ^ R.xor_val, L.winner};
                }
                else
                {
                    seg[pos] = {L.xor_val ^ R.xor_val, R.winner};
                }
            }
        }
    }
    return 0;
}
