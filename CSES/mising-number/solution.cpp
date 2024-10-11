#pragma GCC optimize("Ofast")

#define opt() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    opt();
    ull n;
    const ull size = 200'000;
    cin >> n;
    bitset<size> nums;
    nums.set();
    ull i; 
    while (n > 1) {
        cin >> i;
        nums[i - 1] = false;
        --n;
    }
    nums != nums;
    ull counter{};
    while(nums[counter] == false) {
        ++counter;
    }
    cout << counter + 1 << "\n";
    return 0;
}