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
template<class T> void remdup(vector<T> &v) { // sort and remove duplicates
  sort(all(v)); v.erase(unique(all(v)), end(v));
}
template <class T> T sum(vector<T> &v) {
  if (v.empty()) return 0LL;
  T sum = v[0];
  for (int i = 1; i < (int) v.size(); i++) {
    sum += v[i];
  }
  return sum;
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void solve() {
  int a,b; cin >> a >> b;
  string s; cin >> s;
  int ac = 0, bc = 0;
  for (auto const& c : s) {
    if (c == '0') {
      ac++;
    } else if (c == '1') {
      bc++;
    }
  }
  int s1 = 0, e1 = sz(s) - 1;
  while (s1 <= e1) {
    if (s[s1] == '?' && s[e1] != '?') {
      if (s[e1] == '0') {
        ac++;
        s[s1] = '0';
      } else {
        bc++;
        s[s1] = '1';
      }
    } else if (s[s1] != '?' && s[e1] == '?') {
      if (s[s1] == '0') {
        s[e1] = '0';
        ac++;
      } else {
        s[e1] = '1';
        bc++;
      }
    }
    s1++;
    e1--;
  }
  // Case where you're looking at two ??
  s1 = 0, e1 = sz(s) - 1;
  while (s1 <= e1) {
    int diffa = a - ac;
    int diffb = b - bc;
    int temp = max(diffa,diffb);
    if (s1 == e1 && s[s1] == '?') {
      if (temp == diffa) {
        s[s1] = '0';
        ac++;
      } else {
        bc++;
        s[s1] = '1';
      }
    }
    if (s[s1] == '?' && s[e1] == '?') {
      if (temp == diffa) {
        ac += 2;
        s[s1] = '0';
        s[e1] = '0';
      } else {
        s[s1] = '1';
        s[e1] = '1';
        bc += 2;
      }
    }
    s1++;
    e1--;
  }
  string kekw = s;
  reverse(all(kekw));
  if (kekw != s) {
    cout << "-1\n";
    return;
  }
  if (a == ac && b == bc) {
    cout << s << '\n';
  } else {
    cout << "-1\n";
  }
  return;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
