#pragma GCC optimize("Ofast")

#define opt()                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

// naive O(n^2) solution
ull two_knights_n2(int n) {
  ull total{};
  for (int row{}; row < n; ++row) {
    for (int col{}; col < n; ++col) {
      total += n * n - 1;  // all the other squares
      if (row > 1 && col < n - 1) --total;
      if (row > 0 && col < n - 2) --total;
      if (row < n - 1 && col < n - 2) --total;
      if (row < n - 2 && col < n - 1) --total;
      if (row < n - 2 && col > 0) --total;
      if (row < n - 1 && col > 1) --total;
      if (row > 0 && col > 1) --total;
      if (row > 1 && col > 0) --total;
    }
  }
  return total / 2;
}

vector<ull> solutions(10001, 0);

// recursive solution with memoization
ull two_knights_rec(int n) {
  if (n <= 1) return 0;
  ull total{solutions[n - 1]};
  ull double_entries{};
  // only last row
  for (int col{}, row{n - 1}; col < n; ++col) {
    total += (n - 1) * (n - 1) - 1;  // all the other squares
    if (row > 1 && col < n - 1) --total;
    if (row > 0 && col < n - 2) --total;
    if (row > 0 && col > 1) --total;
    if (row > 1 && col > 0) --total;
    // all positions on the same row, except own position
    double_entries += (n - 1);
    // all positions on the new col on the side, except corner
    double_entries += (n - 1);
    if (col == n - 3 || col == n -2) --double_entries;
  }

  // only last col except bottom right corner
  for (int row{}, col{n - 1}; row < n - 1; ++row) {
    total += (n - 1) * (n - 1) - 1;  // all the other squares
    if (row < n - 2 && col > 0) --total;
    if (row < n - 1 && col > 1) --total;
    if (row > 0 && col > 1) --total;
    if (row > 1 && col > 0) --total;
    // all positions on the same col, except own position
    double_entries += (n - 1);
    // all positions on the new row in the bottom, except corner
    double_entries += (n - 1);
    if (row == n - 3 || row == n -2) --double_entries;
  }

  // remove all solutions that appear twice

  solutions[n] = total + double_entries / 2 ;
  return solutions[n];
}

int main() {
#ifdef READ_FROM_FILE
  [[maybe_unused]] auto ok = freopen("input.txt", "r", stdin);
  ok = freopen("output.txt", "w", stdout);
#endif
  opt();
  int t;
  cin >> t;
  for (int i{1}; i <= t; ++i) {
    cout << two_knights_rec(i) << "\n";
  }

  return 0;
}