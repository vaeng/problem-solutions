/*
The input begins with two positive integers n k (n, k<=107). The next n lines of input contain one positive integer ti, not greater than 109, each.
Output

Write a single integer to output, denoting how many integers ti are divisible by k.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int n, k, ti, counter = 0;
    cin >> n >> k;
    while(n--)
    {
        cin >> ti;
        if(ti % k == 0)
            counter++;
    }
    cout << counter << "\n";
}