/*
Two queen scenario:

Board size n | Number of ways q(n)
1       0
2       0
3       8
4       44
5       140
6       340
7       700
8       1288
9       2184
10      3480
*/

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

// occupied fields by a queen
int occupied_fields(int i, int j, int n)
{
    // rows
    int occupied = 2 * n - 1;
    // top left
    occupied += min(i, j);
    // top right
    occupied += min(n - i - 1, j);
    // bottom left
    occupied += min(n - i - 1, n - j - 1);
    // bottom right
    occupied += min(i, n - j - 1);
    return occupied;
}

// place a queen and check available spots for other queen
int two_queens(int n)
{
    int total{};
    for (int i{0}; i < n; ++i)
    {
        for (int j{0}; j < n; ++j)
        {
            total += n * n - occupied_fields(i, j, n);
        }
    }
    return total / 2;
}

// from n to n+1?

int main()
{
    opt();
#ifdef READ_FROM_FILE
    [[maybe_unused]] auto ok = freopen("input.txt", "r", stdin);
    ok = freopen("output.txt", "w", stdout);
#endif

    for (int i{1}; i <= 10; ++i)
    {
        cout  << two_queens(i) << "\n";
    }

    return 0;
}
