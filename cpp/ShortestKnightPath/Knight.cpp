#include <string>
#include <vector>

#include "../Assert.hpp"

bool is_valid_position(std::string position) {
    if (position.size() != 2) {
        return false;
    }

    if (position[0] - 'a' < 0 || position[0] - 'a' > 7) {
        return false;
    }

    if (position[1] - '1' < 0 || position[1] - '1' > 7) {
        return false;
    }

    return true;
}

void move(std::string position, int mx, int my, std::vector<std::string>& p) {
    std::string next;
    char x = position[0] + mx;
    char y = position[1] + my;
    next.push_back(x);
    next.push_back(y);

    if (is_valid_position(next)) {
        p.push_back(next);
    }
}

int knight(std::string start, std::string finish) {
    std::vector<std::string> current(0);
    std::vector<std::string> next(0);
    current.push_back(start);

    bool found = false;
    int path_count = 0;

    while (!found) {
        while (current.size() > 0) {
            std::string pos = current.back();

            if (pos == finish) {
                return path_count;
            }

            move(pos, 1, 2, next);
            move(pos, -1, 2, next);
            move(pos, 1, -2, next);
            move(pos, -1, -2, next);
            move(pos, 2, 1, next);
            move(pos, -2, 1, next);
            move(pos, 2, -1, next);
            move(pos, -2, -1, next);

            current.pop_back();
        }

        while (next.size() > 0) {
            std::string pos = next.back();
            next.pop_back();
            current.push_back(pos);
        }

        path_count++;
    }
}

int main() {
    Assert::That(knight("a1", "c1"), Equals(2));
    Assert::That(knight("a1", "f1"), Equals(3));
    Assert::That(knight("a1", "f3"), Equals(3));
    Assert::That(knight("a1", "f4"), Equals(4));
    Assert::That(knight("a1", "f7"), Equals(5));

    return 0;
}
