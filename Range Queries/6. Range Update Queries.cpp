#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7; // change Limit

int a[N]; // change datatype
long long int sum[4 * N], lazy[4 * N]; // change datatype

long long int merge (long long int l, long long int r) { // change datatype
    return (l + r); // change operation
}

void add (int node, int b, int e) { // change datatype
    if (lazy[node] == 0) {
        return;
    }

    sum[node] += (1LL * lazy[node] * (e - b + 1)); // change

    int l = (node * 2), r = (node * 2) + 1;

    if (b != e) {
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
    }

    lazy[node] = 0;
}

void build (int node, int b, int e) { //change Datatype
    lazy[node] = 0;

    if (b == e) {
        sum[node] = a[b];
        return;
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    build(l, b, mid);
    build(r, mid + 1, e);

    sum[node] = merge(sum[l], sum[r]);
}

long long int query (int node, int b, int e, int i, int j) { // change datatype
    
    add(node, b, e);

    if (b > j || e < i) {
        return 0; // change value
    }

    if (b >= i && e <= j) {
        return sum[node];
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void update (int node, int b, int e, int i, int j, int val) { // change datatype
    
    add(node, b, e);

    if (b > j || e < i) {
        return;
    }

    if (b >= i && e <= j) {
        lazy[node] = val; // change operation
        add(node, b, e);
        return;
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    update(l, b, mid, i, j, val);
    update(r, mid + 1, e, i, j, val);

    sum[node] = merge(sum[l], sum[r]);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    memset(sum, 0, sizeof(sum));
    memset(lazy, 0, sizeof(lazy));

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int x;
        cin >> x;

        if (x == 1) {
            int l, r, v;
            cin >> l >> r >> v;

            update(1, 1, n, l, r, v);
        }
        else {
            int k;
            cin >> k;

            cout << query(1, 1, n, k, k) << '\n';
        }
    }
    
    return 0;
}
