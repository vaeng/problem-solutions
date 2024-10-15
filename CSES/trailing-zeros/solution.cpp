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
  ull n;
  cin >> n;

  ull fives{};
  
  for (ull i{5}; i <= n; i += 5) {
    ull x = i;
    while (x % 5 == 0) {
      x /= 5;
      ++fives;
    }
  }

  cout << fives << "\n";
  return 0;
}