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
  int n; cin >> n;
  vi mountains(n);
  rep (i, n) cin >> mountains[i];
  sort(all(mountains));
  //  Determine the min abs;
  int min = 1e9;
  int frontm = 0,endm = 0,fronti = 0,endi = 0;
  for (int i = 0; i < n - 1; i++) {
    if (abs(mountains[i + 1] - mountains[i]) < min) {
      min = abs(mountains[i + 1] - mountains[i]);
      frontm = mountains[i];
      endm = mountains[i + 1];
      fronti = i;
      endi = i + 1;
    }
  }
  vi final;
  final.pb(frontm);
  // Find the first element >= frontm
  int temp = 0;
  rep (i,n) {
    if (mountains[i] >= frontm) {
      temp = i;
      break;
    }
  }
  // append all those elements in order
  debug(fronti,endi);
  rep (i,temp,n) {
    if (i != fronti && i != endi){
      debug(mountains[i],i, fronti);
      final.pb(mountains[i]);
    }
  }
  rep (i,temp) {
    if (i != fronti || i != endi) {
      final.pb(mountains[i]);
    }
  }

  final.pb(endm);
  print_v(final);

  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
