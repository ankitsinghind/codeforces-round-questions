#include <iostream>
#include <vector>
using namespace std;

vector<int> constructPermutation(int n, int k) {
    int maxInversions = n * (n - 1) / 2;
    if (k > maxInversions) return {}; // impossible

    vector<int> result;
    int remaining = k;

    for (int i = n; i >= 1; --i) {
        if (remaining >= (i - 1)) {
            result.insert(result.begin(), i); // place at front
            remaining -= (i - 1);
        } else {
            result.push_back(i); // place at end to avoid extra inversions
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> perm = constructPermutation(n, k);
        if (perm.empty()) {
            cout << "0\n";
        } else {
            for (int x : perm) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
