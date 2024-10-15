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

    ull sum1{};
    ull sum2{};
    vi vec1{};
    vi vec2{};
    ull goal{(n + 1) * n / 4};
    for (ull i{n}; i > 0; --i) {
      if (sum1 + i <= goal) {
        vec1.push_back(i);
        sum1 += i;
      } else {
        vec2.push_back(i);
        sum2 += i;
      }
    }
  if (sum1 == sum2) {
    cout << "YES\n";
    cout << vec1.size() << "\n";
    for (auto el : vec1) cout << el << " ";
    cout << "\n";
    cout << vec2.size() << "\n";
    for (auto el : vec2) cout << el << " ";

  } else {
    cout << "NO\n";
  }

  return 0;
}