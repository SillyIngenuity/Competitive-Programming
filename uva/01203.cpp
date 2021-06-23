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
string getstring() {
  string temp; cin >> temp;
  return temp;
}
void solve() {
  // Get all the registers into my priority queue
  // Min heap
  priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> storage;
  string instruction;
  int qnum,period;
  while ((instruction = getstring()) != "#") {
    cin >> qnum >> period;
    // The last int signifies how many times the current period has changed
    // 1 means it is the default
    // Useful to determine how much i increase the period by later
    storage.push(make_tuple(period,qnum,1));
  }
  // Num queries
  int k; cin >> k;
  while (k--) {
    // Print the qnum with highest priority
    cout << get<1>(storage.top()) << '\n';
    int placeholder = get<2>(storage.top()) + 1;
    int newperiod = get<0>(storage.top()) / get<2>(storage.top()) + get<0>(storage.top());
    int qnum1 = get<1>(storage.top());
    storage.pop();
    storage.push(make_tuple(newperiod,qnum1,placeholder));
  }
  return;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
