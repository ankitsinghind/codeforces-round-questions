#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, n;
        cin >> x >> n;
        int result;
    if (n % 2 == 0){
    result = 0;
    }
    else{
    result = x;
    }
    cout << result << endl;
    }

    return 0;
}
