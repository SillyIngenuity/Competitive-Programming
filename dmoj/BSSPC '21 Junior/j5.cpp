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
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
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
template <class F> F ceildiv(F a, F d) { F res = a / d; if (res * d != a) { res += 1&((a<0)^(d>0)); } return res; }
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n = 5 * 100000;
vector<bool> prime;
vi prime1;
vector<ll> prefixsums;
void calc() {
  prime.assign(n, true);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i] == true) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  rep (i,2, n) {
    if (prime[i] == true) {
      prime1.pb(i);
    }
  }
  prefixsums.assign(sz(prime1), 0);
  rep(i,sz(prime1)) {
    if (i > 0) prefixsums[i] += prefixsums[i - 1];
    prefixsums[i] += prime1[i];
  }
}
void solve() {
  int x,k; cin >> x >> k;
  int index = (int)lowb(prime1,x);
  cout << prime1[k + index - 1] << " " <<prefixsums[k + index - 1] - (index == 0 ? 0 : prefixsums[index - 1]) << '\n';
  return;
}
int main() {
  int t;
  cin >> t;
  calc();
  while (t--) {
    solve();
  }
  return 0;
}
