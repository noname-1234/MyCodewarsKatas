#include <string>

#include "../Assert.hpp"

using namespace std;

string rot13(string msg) {
    string ret = "";
    for (int i = 0; i < msg.size(); i++) {
        char c = msg[i];
        if (c >= 'A' && c <= 'A' + 25) {
            ret += 'A' + (((c - 'A' + 13) % 26));
        } else if (c >= 'a' && c <= 'a' + 25) {
            ret += 'a' + (((c - 'a' + 13) % 26));
        } else {
            ret += c;
        }
    }
    return ret;
}

int main() {
    Assert::That(rot13("test"), Equals("grfg"));
    Assert::That(rot13("Test"), Equals("Grfg"));
    Assert::That(rot13("AbCd"), Equals("NoPq"));
}