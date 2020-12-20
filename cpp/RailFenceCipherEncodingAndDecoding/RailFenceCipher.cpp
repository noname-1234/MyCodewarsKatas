#include "../Assert.hpp"

std::string encode_rail_fence_cipher(const std::string &str, int n) {
    std::string result;

    int wave_length = 2 * n - 2;

    for (int l = 0; l < n; l++) {
        int d = wave_length - 2 * l;
        for (int i = l; i < str.size(); i += d, d = wave_length - d) {
            result += str[i];
            if (d == 0) {
                d = wave_length;
            }
        }
    }

    return result;
}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
    std::string result((int)str.size(), ' ');

    int wave_length = 2 * n - 2;
    int c = 0;

    for (int l = 0; l < n; l++) {
        int d = wave_length - 2 * l;
        for (int i = l; i < str.size(); i += d, d = wave_length - d, c++) {
            result[i] = str[c];
            if (d == 0) {
                d = wave_length;
            }
        }
    }

    return result;
}

int main() {
    Assert::That(encode_rail_fence_cipher("WEAREDISCOVEREDFLEEATONCE", 3),
                 Equals("WECRLTEERDSOEEFEAOCAIVDEN"));
    Assert::That(encode_rail_fence_cipher("Hello, World!", 3),
                 Equals("Hoo!el,Wrdl l"));
    Assert::That(encode_rail_fence_cipher("Hello, World!", 4),
                 Equals("H !e,Wdloollr"));
    Assert::That(encode_rail_fence_cipher("", 3), Equals(""));

    Assert::That(decode_rail_fence_cipher("H !e,Wdloollr", 4),
                 Equals("Hello, World!"));
    Assert::That(decode_rail_fence_cipher("WECRLTEERDSOEEFEAOCAIVDEN", 3),
                 Equals("WEAREDISCOVEREDFLEEATONCE"));
    Assert::That(decode_rail_fence_cipher("", 3), Equals(""));

    return 0;
}