/*
 Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!
Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1'000'000'000, n-m<=100'000) separated by a space.
Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
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

vector<bool> sieve(ll limit)
{
    vector<bool> sieve(limit+1, true);
    sieve.at(0) = false;
    sieve.at(1) = false;
    for(ll current_prime{2}; current_prime*current_prime <= limit; ++current_prime) {
        if (sieve.at(current_prime)) {
            for(ll i{current_prime * current_prime}; i <= limit; i += current_prime) {
                sieve.at(i) = false;
            }
        }
    }
    return sieve;
}

vector<bool> mod_sieve(ull limit)
{
    vector<bool> is_prime(limit+1, true);
    vector<ull> spf(limit+1, 0);
    vector<ull> primes{2};
    is_prime.at(0) = false;
    is_prime.at(1) = false;
    for(ull i{2}; i < limit; ++i) {
        if (is_prime.at(i)) {
            primes.push_back(i);
            spf.at(i) = i;
        }
        for(ull j : primes) {
            ull p{spf.at(i)};
            if (j > p || i * p > limit) break;
            is_prime.at(i*p) = false;
            spf.at(i*p) = j;
        }
    }
    return is_prime;
}


bool is_prime(ll candidate, vector<bool> primes) {
    return primes.at(candidate);
}

int main()
{
    opt();
#ifdef READ_FROM_FILE
    [[maybe_unused]] auto ok = freopen("input.txt", "r", stdin);
    ok = freopen("output.txt", "w", stdout);
#endif
    ll limit{1'000'000'000};
    auto primes{sieve(limit)};
    int t;
    ll n, m;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (ll i{m}; i <= n; ++i)
        {
            if (is_prime(i, primes))
                cout << i << "\n";
        }
        if (t > 0) cout << "\n";
    }

    return 0;
}
