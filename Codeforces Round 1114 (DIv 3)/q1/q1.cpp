#include <iostream>

using namespace std;

int solve() {
    int p, q, r;
    cin >> p >> q >> r;

    int rounds = 0;

    while (p != q && q != r && p != r) {

        if (p > q) swap(p, q);
        if (q > r) swap(q, r);
        if (p > q) swap(p, q);

        // r is largest, p is smallest
        r--;
        p++;
        rounds++;
    }

    return rounds;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            cout << solve() << "\n";
        }
    }
    return 0;
}
