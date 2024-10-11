#pragma GCC optimize("Ofast")

#define opt() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    opt();
    string s;
    getline(cin, s);
    ull counter{0};
    ull max{0};
    char last{s.at(0)};
    for (char c : s) {
        if (last == c) {
            ++counter;
        } else {
            max = max > counter ? max : counter;
            counter = 1;
            last = c;
        }
    }
    cout << ((max > counter) ? max : counter);
    return 0;
}