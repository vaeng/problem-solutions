/*Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything.

More precisely... rewrite small numbers from input to output. Stop processing input after reading in the number 42. All numbers at input are integers of one or two digits.
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (true)
    {
        cin >> n;
        if (n == 42)
            break;
        cout << n << "\n";
    }
}