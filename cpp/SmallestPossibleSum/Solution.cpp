#include <vector>

#include "../Assert.hpp"

unsigned long long get_gcf(unsigned long long a, unsigned long long b) {
    while (true) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

unsigned long long solution(const std::vector<unsigned long long>& arr) {
    if (arr.size() == 0) {
        return 0;
    }

    if (arr.size() == 1) {
        return arr[0];
    }

    unsigned long long gcf = get_gcf(arr[0], arr[1]);

    for (int i = 2; i < arr.size(); i++) {
        if (gcf == 1) {
            break;
        }

        unsigned long long a = arr[i];

        if (a % gcf != 0) {
            gcf = get_gcf(a, gcf);
        }
    }

    return gcf * arr.size();
}

int main() {
    Assert::That(solution({1, 21, 55}), Equals(3));
    Assert::That(solution({3, 13, 23, 7, 83}), Equals(5));
    Assert::That(solution({4, 16, 24}), Equals(12));
    Assert::That(solution({30, 12}), Equals(12));
    Assert::That(solution({60, 12, 96, 48, 60, 24, 72, 36, 72, 72, 48}),
                 Equals(132));
    Assert::That(solution({71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71}),
                 Equals(923));
    Assert::That(solution({11, 22}), Equals(22));
    Assert::That(solution({9}), Equals(9));
    Assert::That(solution({1}), Equals(1));
    Assert::That(solution({9, 9}), Equals(18));

    return 0;
}