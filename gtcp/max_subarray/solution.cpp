/*
Test case scenarios and solutions.

First line, number of cases, second line, number of elements, subsequent lines are arrays:

6
40
-83802 -28390 -84570 -36309 -60181 -50457 -32859 -48824 -6134 -52159 -68979 -4127 -94123 -33469 -10645 -50470 -25288 -68054 -39999 -87040 -73539 -87011 -440 -63948 -64207 -49397 -66832 -93442 -33955 -25587 -79304 -33323 -12137 -58759 -30978 -88878 -34498 -33068 -63736 -54528
25010 8375 13699 78910 79846 77384 96564 95246 51034 58222 73701 53565 96540 63766 25661 28944 9717 31794 35003 71946 57634 17218 42434 64967 62378 4878 59478 9999 8799 49624 79616 51579 15800 94806 52885 98301 84123 42055 99575 34160
0 0 -3960 2904 -70115 -27933 0 0 17755 0 0 0 0 0 -78175 0 92530 0 0 0 0 -4914 -76142 -76866 91810 77687 0 0 23170 0 33508 0 0 0 0 64281 92343 -45047 0 -20280
-86126 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
-7105 -49119 69873 -81680 -8227 81579 47099 45520 -96445 80991 45639 -53670 -13061 19120 89327 51860 53629 -65834 -95127 80028 78443 68959 72484 81669 31728 -44252 -68308 48807 -90474 28799 -69728 -51154 1592 5736 -73890 -18633 12609 -55863 -86802 -28904
-84586 -63781 49410 -24228 28139 97882 -17587 31583 82240 47473 5956 84876 -20878 -15917 -75765 -62503 -41020 -63111 61270 -10352 -54283 -86645 -90951 46754 -59521 -30468 66878 66789 18287 86673 -15620 30583 654 -15082 -76976 -67845 55976 -8009 -96161 12253

Correspond to the following (edge) case scenarios:

All Negative Numbers: -440
All Positive Numbers: 2,105,236
Zeros and Mixed Numbers: 382,799
Single Element: 0
Normal Case: 603,938
Normal Case: 385,744
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

int main()
{
    opt();
#ifdef READ_FROM_FILE
    [[maybe_unused]] auto ok = freopen("input.txt", "r", stdin);
    ok = freopen("output.txt", "w", stdout);
#endif
    ll n, m, t;
    cin >> n >> m;
    vector<ll> array;
    array.reserve(m);
    for (int i{}; i < n; ++i)
    {
        array.clear();
        ll best{LLONG_MIN};
        for (int j{}; j < m; ++j)
        {
            cin >> t;
            array.push_back(t);
        }

        ll current{array.at(0)};
        for (int j{1}; j < m; ++j)
        {
            if (current < 0)
                current = array.at(j);
            else
                current += array.at(j);
            best = current > best ? current : best;
        }
        cout << best << "\n";
    }

    return 0;
}