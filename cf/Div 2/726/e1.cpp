#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define si stack<int>
#define vvi vector <vector<int>>
#define vll vector<long long>
#define tii tuple<int, int>
#define vtii vector<tuple<int, int>>
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
// Alex's cool rep :O
#define repb(i, b) for (int i = 0; i < (b); ++i)
#define repab(i, a, b) for (int i = (a); i < (b); ++i)
#define GET_REP(_1, _2, _3, NAME,...) NAME
#define rep(...) GET_REP(__VA_ARGS__, repab, repb)(__VA_ARGS__)
#ifdef LOCAL
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args> void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
#else
#define debug(...) 0
#endif
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rint (int a, int b) { // inclusive bounds
  return uniform_int_distribution<int>(a, b)(rng);
}
double rdouble(double a, double b) {
  return uniform_real_distribution<double>(a, b)(rng);
}
// Random library of functions
template <class F> void print_v(vector<F> v) {
  rep(i,sz(v)) cout << v[i] << " ";
  cout << '\n';
}
template <class F> void print_m(vector<F> v) {
  rep (i,sz(v)) {
    rep (j, sz(v[i])) {
      cout << v[i][j] << " ";
    }
    cout << '\n';
  }
}
template <class F> void fill_m(vector<F> &v, int num) {
  rep (i,sz(v)) {
    rep (j, sz(v[i])) {
      v[i][j] = num;
    }
  }
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  // I compute every possible string and find the lexicographically smallest one
  vector<string> storage;
  int len = n;
  while (len >= 1) {
    string temp = s;
    int templen = len;
    while (templen < k) {
      // Duplicate this bitch
      temp +=temp;
      templen *= 2;
    }
    debug(temp);
    // Trim temp until length k;
    while (templen > k) {
      temp.pop_back();
      templen--;
    }
    storage.pb(temp);
    // Remove the last letter
    s.pop_back();
    len--;
  }
  // Find the lexi smallest string in storage

  // string ans will be the smallest
  string ans = storage[0];

  for (int i = 0; i < (int)storage.size(); i++) {
    if (lexicographical_compare(all(storage[i]),all(ans))) {
      ans = storage[i];
    }
  }
  cout << ans << '\n';
  return;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
