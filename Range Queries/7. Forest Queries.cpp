#include <bits/stdc++.h>

using namespace std; 



int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    int a[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int ii = 1; ii <= n; ii++) {
            char ch;
            cin >> ch;

            if (ch == '*') {
                a[i][ii] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int ii = 1; ii <= n; ii++) {
            a[i][ii] += a[i - 1][ii] + a[i][ii - 1] - a[i - 1][ii - 1];
        }
    }

    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1]) << '\n';
    }
    
    return 0;
}
