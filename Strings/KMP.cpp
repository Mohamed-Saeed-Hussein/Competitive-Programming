vector<int> prefix_function(const string &s) {
  int n = s.size(), k = 0;
  vector<int> prefix(n);
  for (int i = 1; i < n; ++i) {
    while (k > 0 and s[i] != s[k]) {
      k = prefix[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    prefix[i] = k;
  }
  return prefix;
}

vector<int> KMP(string pattern, string s) {
  int k = 0;
  vector<int> pref = prefix_function(pattern), ret;
  for (int i = 0; i < s.size(); ++i) {
    while (k > 0 and s[i] != pattern[k]) {
      k = pref[k - 1];
    }

    if (s[i] == pattern[k]) {
      ++k;
    }

    if (k == pattern.size()) {
      ret.push_back(i - k + 1);
      k = pref[k - 1];
    }
  }
  return ret;
}
