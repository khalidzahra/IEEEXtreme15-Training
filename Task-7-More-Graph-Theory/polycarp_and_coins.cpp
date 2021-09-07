#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long n;
        cin >> n;
        /*
         * We want 2x + y = n and |y - x| as little as possible.
         * We can find a precise solution by differentiating the square error between x and y
         * d/dx((y-x)^2) = 0
         * d/dx((n - 3x)^2) = 0
         * -6x(n-3x) = 0
         * x = n / 3 and y = n - 2 * n / 3
         */
        int x = n / 3, y = n - 2 * n / 3;
        if (n - 2 * x - y == 1) {
            if (y > x) {
                y--;
                x++;
            } else y++;
        }
        if (n - 2 * x - y == 2) x++;
        cout << y << " " << x << endl;
    }
    return 0;
}

