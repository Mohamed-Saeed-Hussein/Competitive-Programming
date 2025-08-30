vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  int left = 0, right = 0;
  for (int i = 1; i < n; i++) {
    if (i < right) {
      z[i] = min(right - i, z[i - left]);
    }
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > right) {
      left = i;
      right = i + z[i];
    }
  }
  return z;
}