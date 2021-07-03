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
void solve(int cases) {
  int k; cin >> k;
  // gonna use a vector to check for uniquness later
  vi visited(10001);
  vector<double> friends(k);
  map<int,unordered_set<int>> storage;
  int person = 0;
  while (k--) {
    // I probably want a map pointing to a vector
    unordered_set<int> stamps;
    unordered_set<int> newstamps;
    int n; cin >> n;
    while (n--) {
      int stamp; cin >> stamp;
      if (newstamps.find(stamp) == newstamps.end()) {
        visited[stamp]++;
        newstamps.insert(stamp);
      }
      stamps.insert(stamp);
    }
    storage[person] = stamps;
    person++;
  }
  // Count how many uniques each friend has and the total uniques
  double total = 0;
  int current = 0;
  for (auto const& [key,stamps] : storage) {
    for (auto const& stamp : stamps) {
      if (visited[stamp] > 1) {
        // its not unique
        continue;
      } else {
        friends[current]++;
        total++;
      }
    }
    current++;
  }
  cout << "Case " << cases << ": ";
  rep (i, sz(friends)) {
    double temp = 0;
    if (total > 0) {
      temp = (friends[i] / total) * 100;
    }
    cout << fixed << setprecision(6);
    if (i == sz(friends) - 1) {
      cout << temp << "%";
    } else {
      cout << temp << "% ";
    }
  }
  cout << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int cases = 1;
  while (t--) {
    solve(cases);
    cases++;
  }
  return 0;
}
