#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    long long int a[n], prefix_sum[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        sum += a[i];

        prefix_sum[i] = sum;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        l--; r--;

        if (l == 0) {
            cout << prefix_sum[r] << '\n';
        }
        else {
            cout << (prefix_sum[r] - prefix_sum[l - 1]) << '\n';
        }
    }
    
    return 0;
}
