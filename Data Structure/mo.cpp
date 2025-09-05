#include "bits/stdc++.h"

using namespace std;

const int N = 1e6 + 9, SQ = 440;

struct query {
  int l, r, id;
  bool operator<(const query &x) const {
    if (l / SQ == x.l / SQ) return ((l / SQ) & 1) ? r > x.r : r < x.r;
    return l / SQ < x.l / SQ;
  }
} Q[N];
int cnt[N], arr[N];
long long sum;
void add_left(int i) {
  int x = arr[i];
  sum += 1LL * (cnt[x] + cnt[x] + 1) * x;
  ++cnt[x];
}
void add_right(int i) {
  int x = arr[i];
  sum += 1LL * (cnt[x] + cnt[x] + 1) * x;
  ++cnt[x];
}
void remove_left(int i) {
  int x = arr[i];
  sum -= 1LL * (cnt[x] + cnt[x] - 1) * x;
  --cnt[x];
}
void remove_right(int i) {
  int x = arr[i];
  sum -= 1LL * (cnt[x] + cnt[x] - 1) * x;
  --cnt[x];
}
long long ans[N];
void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> Q[i].l >> Q[i].r;
    Q[i].id = i;
  }
  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l, R = Q[i].r;
    if (R < l) {
      while (l > L) {
        add_left(--l);
      }
      while (l < L) {
        remove_left(l++);
      }
      while (r < R) {
        add_right(++r);
      }
      while (r > R) {
        remove_right(r--);
      }
    } else {
      while (r < R) {
        add_right(++r);
      }
      while (r > R) {
        remove_right(r--);
      }
      while (l > L) {
        add_left(--l);
      }
      while (l < L) {
        remove_left(l++);
      }
    }
    ans[Q[i].id] = sum;
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  solve();
  return 0;
}