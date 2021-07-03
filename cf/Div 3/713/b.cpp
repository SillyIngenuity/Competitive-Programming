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
      cout << v[i][j];
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
  int n; cin >> n;
  vector<string> field(n);
  rep (i,n) cin >> field[i];
  vector<pair<int,int>> coor;
  // find where the two stars are located
  rep (i, n) {
    rep (j, n) {
      if (field[i][j] == '*') {
        coor.pb(make_pair(i,j));
      }
    }
  }
  // Find out what coordinates to place the new stars at 

  // First case: if the stars are horizontally on the same line
  // Place it one under or one up
  if (coor[1].second == coor[0].second) {
    if (coor[1].second + 1 < n) {
      // we can place it under
      field[coor[1].first][coor[1].second + 1] = '*';
      field[coor[0].first][coor[0].second + 1] = '*';
    } else {
      field[coor[1].first][coor[1].second - 1] = '*';
      field[coor[0].first][coor[0].second - 1] = '*';
    }
  } else if (coor[1].first == coor[0].first) {
    // same vertical line
    if (coor[1].first + 1 < n) {
      // to the right
      field[coor[1].first + 1][coor[1].second] = '*';
      field[coor[0].first + 1][coor[0].second] = '*';
    } else {
      field[coor[1].first - 1][coor[1].second] = '*';
      field[coor[0].first - 1][coor[0].second] = '*';
    }

  } else {
    // work off first star
    // start is left or right of the first star, and in the same column as the second start
    field[coor[1].first][coor[0].second] = '*';
    field[coor[0].first][coor[1].second] = '*';
  }

  print_m(field);
  // They're randomly placed
  // In this case just line em up
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
