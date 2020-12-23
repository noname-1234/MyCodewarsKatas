#include <vector>

#include "../Assert.hpp"

using ull = unsigned long long;
using namespace std;

ull exp_sum(unsigned int n) {
    if (n == 0) return 1;
    vector<vector<ull>> dp(n, vector<ull>(1, 1));
    for (unsigned int m = 1; m < n; m++) {
        for (unsigned int i = m; i < n; i++) {
            ull a, b;
            if (i < m + 1) {
                a = 1;
            } else if (2 * m + 1 > i) {
                a = dp[i - m - 1][i - m - 1];
            } else {
                a = dp[i - m - 1][m];
            }

            b = dp[i][m - 1];
            dp[i].push_back(a + b);
        }
    }
    return dp[n - 1][n - 1];
}

int main() {
    Assert::That(exp_sum(1), Equals(1));
    Assert::That(exp_sum(2), Equals(2));
    Assert::That(exp_sum(3), Equals(3));
    Assert::That(exp_sum(5), Equals(7));
    Assert::That(exp_sum(10), Equals(42));
}