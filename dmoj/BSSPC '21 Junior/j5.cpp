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
bool prime[500001];
void SieveOfEratosthenes(vi &prime1)
{
  // Create a boolean array
  // "prime[0..n]" and initialize
  // all entries it as true.
  // A value in prime[i] will
  // finally be false if i is
  // Not a prime, else true.
  memset(prime, true, sizeof(prime));
 
  for (int p = 2; p * p <= n; p++)
    {
      // If prime[p] is not changed,
      // then it is a prime
      if (prime[p] == true)
        {
          // Update all multiples
          // of p greater than or
          // equal to the square of it
          // numbers which are multiple
          // of p and are less than p^2
          // are already been marked.
          for (int i = p * p; i <= n; i += p)
            prime[i] = false;
        }
    }
  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      prime1.push_back(p);
    }
    
  }
} 
void solve(vi &prime1) {
}
int main() {
  int t;
  cin >> t;
  vi prime1;
  SieveOfEratosthenes(prime1);
  while (t--) {
    solve(prime1);
  }
  return 0;
}
