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
#define rep(i,a,b) for (int i = a; i < b; i++)
#define re(i, b) for (int i = 0; i < b; i++)
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << '\n';
  cout.flush();
}
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rint (int a, int b) { // inclusive bounds
  return uniform_int_distribution<int>(a, b)(rng);
}
double rdouble(double a, double b) {
  return uniform_real_distribution<double>(a, b)(rng);
}
// Random library of functions
template <class F> void print_v(vector<F> v) {
  re(i,sz(v)) cout << v[i] << " ";
  cout << '\n';
}
template <class F> void print_m(vector<F> v) {
  re (i,sz(v)) {
    re (j, sz(v[i])) {
      cout << v[i][j] << " ";
    }
    cout << '\n';
  }
}
template <class F> void fill_m(vector<F> &v, int num) {
  re (i,sz(v)) {
    re (j, sz(v[i])) {
      v[i][j] = num;
    }
  }
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void print_ll(list<string> final) {
  for (auto v: final) {
    cout << v;
  }
  cout << '\n';
}
void solve(string &s){
  string temp = "";
  list <string> final;
  char previous = ' ';
  string temp1 = "";
  re (i, (int) s.size()) {
    if (s[i] == '[') {
      if (previous == '[') {
        final.push_front(temp);
        temp.clear();
      } else if (previous == ']') {
        final.pb(temp);
        temp.clear();
      }
      previous = s[i];
      continue;
    } else if (s[i] == ']') {
      if (previous == '[') {
        final.push_front(temp);
        temp.clear();
      } else if (previous == ']') {
        final.pb(temp);
        temp.clear();
      }
      previous = s[i];
      continue;
    }
    if (previous != ' ') {
      final.pb(temp1);
      temp1.clear();
      temp = temp + s[i];
    } else {
      temp1 = temp1 + s[i];
    }
  }
  if (previous == '[') {
    final.push_front(temp);
  } else {
    final.pb(temp);
  }
  print_ll(final);
  return;
}
int main() {
  string s;
  while (cin >> s) {
    solve(s);
  }
  return 0;
}
