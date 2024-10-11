#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    long long unsigned int n{0};
    cin >> n;
    while (true) {
        cout << n << " ";
        if (n == 1) break;
        n = n % 2 ? n * 3 + 1 : n / 2;
    } while(n != 1);
    return 0;
}