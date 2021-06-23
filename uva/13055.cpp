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
 void print_ss(stack<string> s) {
  if (s.empty()) return;
  string x = s.top();
  s.pop();
  cout << x << ' ';
  print_ss(s);
  s.push(x);
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
stack<string> names;
void solve(){
  string command,name;
  cin >> command;
  if (command == "Test") {
    if (names.empty()) {
      cout << "Not in a dream\n";
    } else {
      string temp = names.top();
      cout << temp << '\n';
    }
  } else if (command == "Sleep") {
    cin >> name;
    names.push(name);
  } else {
    if (!names.empty()) {
      names.pop();
    }
  }
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
