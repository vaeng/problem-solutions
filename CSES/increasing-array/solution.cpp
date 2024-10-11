#pragma GCC optimize("Ofast")

#define opt() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    opt();
    ull n{};
    cin >> n;
    ull moves{};
    ull j{};
    ull i{}; 
    while (n > 0) {
        cin >> i;
        if ( i < j) moves += j - i;
        else j = i;
        --n;
    }
    cout << moves << "\n";
    return 0;
}