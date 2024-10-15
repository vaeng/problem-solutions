#pragma GCC optimize("Ofast")

#define opt()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

bool valid(int a[], size_t n)
{
    for (size_t i{}; i < n - 1; ++i)
    {
        if (abs(a[i] - a[i + 1]) == 1)
            return false;
    }
    return true;
}

int main()
{
#ifdef READ_FROM_FILE
    [[maybe_unused]] auto ok = freopen("input.txt", "r", stdin);
    ok = freopen("output.txt", "w", stdout);
#endif
    opt();
    int n;
    cin >> n;
    int v[n];

    // fill the even numbers into the first half
    for (int i{0}; i <= n / 2; ++i)
    {
        v[i] = (i + 1) * 2;
    }

    // fill the odd numbers into the second half
    for (int i{0}; i <= n / 2; ++i)
    {
        v[i + n / 2] = (i * 2 + 1);
    }

    if (valid(v, n))
    {
        for (auto &el : v)
        {
            cout << el << " ";
        }
    }
    else
    {
        cout << "NO SOLUTION";
    }
    cout << "\n";
    return 0;
}