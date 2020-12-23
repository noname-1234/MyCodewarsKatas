#include <utility>

#include "../Assert.hpp"
#include "math.h"

using namespace std;

class GapInPrimes {
   public:
    static bool isPrime(long long v) {
        for (long long i = 2; i <= sqrt(v); i++) {
            if (v % i == 0) {
                return false;
            }
        }
        return true;
    }
    static pair<long long, long long> gap(int g, long long m, long long n) {
        long long head = 0;
        for (long long i = m; i <= n; i++) {
            if (isPrime(i)) {
                if (head == 0) {
                    head = i;
                    continue;
                }
                if (i - head == g) {
                    return {head, i};
                }
                head = i;
            }
        }
        return {0, 0};
    }
};

void testequal(pair<long long, long long> ans, pair<long long, long long> sol) {
    Assert::That(ans.first, Equals(sol.first));
    Assert::That(ans.second, Equals(sol.second));
}

void dotest(int g, long long m, long long n, pair<long long, long long> expected) {
    cout << "Test {" << g << ", " << m << ", " << n << "} :" << endl;
    testequal(GapInPrimes::gap(g, m, n), expected);
}

int main() {
    dotest(2, 100, 110, {101, 103});
    dotest(4, 100, 110, {103, 107});
    dotest(6, 100, 110, {0, 0});
    dotest(8, 300, 400, {359, 367});
    dotest(10, 300, 400, {337, 347});
}
