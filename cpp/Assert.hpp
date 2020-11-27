#ifndef _ASSERT_HPP_
#define _ASSERT_HPP_

#include <iostream>

enum Operator
{
    Equal,
};

template<typename T>
class Compare
{
    public:
        Compare(T& Value, Operator Op) : Value(Value), Op(Op) {}
        T Value;
        Operator Op;
};

template<typename T>
Compare<T>* Equals(T Value)
{
    Operator op = Operator::Equal;
    return new Compare<T>(Value, op);
}

namespace Assert
{
    template<typename T>
    void That(T& Expect, Compare<T>* Actual)
    {

        bool condition = false;
        switch (Actual->Op)
        {
        case Operator::Equal:
            condition = (Expect == Actual->Value);
            break;
        
        default:
            break;
        }

        std::cout << ((condition)? "PASS" : "FAILED") << std::endl;
    }

    void That(int Expect, Compare<int>* Actual)
    {
        Assert::That<int>(Expect, Actual);
    }
}

#endif // _ASSERT_HPP_