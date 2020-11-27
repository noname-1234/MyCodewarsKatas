#include <string>
#include <vector>

using namespace std;

int precedence(char c)
{
    switch (c)
    {
        case('^'):
            return 2;
        case('*'):
            return 1;
        case('/'):
            return 1;
    }
    return 0;
}

string to_postfix(string infix)
{
    vector<char> heap(0, 0);
    string ret = "";

    for(int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            for(int j = 0; j < infix.size() - i; j++)
            {
                if (infix[i+j] == ')')
                {
                    ret += to_postfix(infix.substr(i + 1, j - 1));
                    i = i + j;
                    break;
                }
            }
            continue;
        }
        else if (isdigit(infix[i]))
        {
            ret += infix[i];
        }
        else
        {
            char op = infix[i];

            while (heap.size() != 0 && precedence(op) <= precedence(heap.back()))
            {
                ret += heap.back();
                heap.pop_back();
            }

            heap.push_back(op);
        }
    }

    while(heap.size() > 0)
    {
        ret += heap.back();
        heap.pop_back();
    }

    return ret;
}

int main()
{
    string str1 = to_postfix("2+7*5");
    string str2 = to_postfix("3*3/(7+1)");
    string str3 = to_postfix("5+(6-2)*9+3^(7-1)");
    string str4 = to_postfix("(5-4-1)+9/5/2-7/1/7");

    return 0;
}