#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long long int n;
    cin >> n;

    while (n != 1) {
        cout << n << ' ';

        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n++;
        }
    }
    cout << n << '\n';

    return 0;
}
