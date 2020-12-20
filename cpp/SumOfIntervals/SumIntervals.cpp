#include <utility>
#include <vector>

#include "../Assert.hpp"

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    int sum = 0;

    int min = INT32_MAX;
    int max = INT32_MIN;
    for (int i = 0; i < intervals.size(); i++) {
        std::pair<int, int> interval = intervals[i];

        if (interval.first < min) {
            min = interval.first;
        }
        if (interval.second > max) {
            max = interval.second;
        }
    }

    std::vector<int> arr(max - min + 1, 0);
    for (int i = 0; i < intervals.size(); i++) {
        std::pair<int, int> interval = intervals[i];
        arr[interval.first - min] += 1;
        arr[interval.second - min] -= 1;
    }

    int overlapped = 0;
    int start = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            if (overlapped == 0) {
                start = i;
            }

            overlapped += arr[i];

            if (overlapped == 0) {
                sum += (i - start);
            }
        }
    }

    return sum;
}

int main() {
    std::vector<std::pair<int, int>> intervals = {{1, 5}};
    Assert::That(sum_intervals(intervals), Equals(4));

    intervals = {{1, 4}, {7, 10}, {3, 5}};
    Assert::That(sum_intervals(intervals), Equals(7));

    intervals = {{1, 5}, {6, 10}};
    Assert::That(sum_intervals(intervals), Equals(8));

    intervals = {{1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}};
    Assert::That(sum_intervals(intervals), Equals(19));

    intervals = {{485, 496}, {287, 359}, {485, 496}, {71, 82}, {-124, 86}, {-282, 213}, {481, 500}, {0, 282}, {419, 500}, {333, 467}, {387, 452}, {-454, -338}, {315, 357}, {-26, 227}, {-117, 273}, {-255, 250}};
    Assert::That(sum_intervals(intervals), Equals(893));

    return 0;
};
