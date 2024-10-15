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
  cout << static_cast<ull>(powl(2, n)) % (1'000'000'007) << "\n";

  return 0;
}