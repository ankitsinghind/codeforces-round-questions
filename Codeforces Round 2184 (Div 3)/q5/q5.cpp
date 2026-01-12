#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<int> diff(n - 1);
        for (int i = 0; i < n - 1; i++)
            diff[i] = abs(p[i] - p[i + 1]);

        vector<long long> cnt(n + 2, 0);
        vector<int> left(n - 1), right(n - 1);
        stack<int> st;

        for (int i = 0; i < n - 1; i++)
        {
            while (!st.empty() && diff[st.top()] >= diff[i])
                st.pop();
            if (st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && diff[st.top()] > diff[i])
                st.pop();
            if (st.empty())
                right[i] = n - 1 - i;
            else
                right[i] = st.top() - i;
            st.push(i);
        }

        for (int i = 0; i < n - 1; i++)
        {
            long long contrib = 1LL * left[i] * right[i];
            cnt[1] += contrib;
            cnt[diff[i] + 1] -= contrib;
        }

        for (int k = 1; k < n; k++)
        {
            cnt[k] += cnt[k - 1];
            if (k == n - 1)
                cout << cnt[k] << '\n';
            else
                cout << cnt[k] << ' ';
        }
    }
    return 0;
}
