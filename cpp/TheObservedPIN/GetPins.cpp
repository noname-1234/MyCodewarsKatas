#include <string>
#include <vector>

using namespace std;

string get_adjacent(char k)
{
    static vector<vector<char>> kp {
        vector<char>{'1', '2', '3'},
        vector<char>{'4', '5', '6'},
        vector<char>{'7', '8', '9'},
        vector<char>{ 0,  '0',  0 },
    };

    if (k == '0')
    {
        return "08";
    }

    int ik = k - '0';

    if (ik < 1 || ik > 9)
    {
        return "";
    }

    int r = (ik - 1) / 3;
    int c = (ik - 1) % 3;

    string ret(1, k);
    // get up
    if (r > 0)
    {
        ret += kp[r - 1][c];
    }
    // get left
    if (c > 0)
    {
        ret += kp[r][c - 1];
    }
    // get bottom
    if (r < 2 || (r == 2 && c == 1))
    {
        ret += kp[r + 1][c];
    }
    // get right
    if (c < 2)
    {
        ret += kp[r][c + 1];
    }

    return ret;
}

std::vector<std::string> get_pins(std::string observed) {

    if (observed.size() == 0)
    {
        return vector<string>(0);
    }

    vector<string> ret(1, "");

    for(int i = 0; i < (int)observed.size(); i++)
    {
        char k = observed[i];
        string adj_keys = get_adjacent(k);

        vector<string> tmp(0);
        for (int j = 0; j < (int)ret.size(); j++)
        {
            for(int k = 0; k < (int)adj_keys.size(); k++)
            {
                tmp.push_back(ret[j] + adj_keys[k]);
            }
        }
        ret = tmp;
    }

    return ret;
}

int main()
{
    vector<string> pins = get_pins("11");

    return 0;
}