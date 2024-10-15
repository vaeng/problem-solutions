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

int main() {
#ifdef READ_FROM_FILE
  [[maybe_unused]] auto ok = freopen("input.txt", "r", stdin);
  ok = freopen("output.txt", "w", stdout);
#endif
  opt();
  ull t, col, row;
  cin >> t;
  while (t--) {
    // x: column, y: row, top left (1,1)
    ull result;
    cin >> row >> col;
    if (row > col) {
      if (row % 2 == 1) {
        result = (row - 1) * (row - 1) + col;
      } else {
        result = row * row - col + 1;
      }
    } else {
      if (col % 2 == 1) {
        result = col * col - row + 1;
      } else {
        result = (col - 1) * (col - 1) + row;
      }
    }
    cout << result << "\n";
  }

  return 0;
}