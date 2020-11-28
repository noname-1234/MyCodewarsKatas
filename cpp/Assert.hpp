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
    template<typename T1, typename T2>
    void That(T1& Expect, Compare<T2>* Actual)
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

        if (condition)
        {
            std::cout << "PASS" << std::endl;
        }
        else
        {
            std::cout << "FAILED, Expect: " << Expect << ", Actual: " << Actual->Value << std::endl;
        }
        

    }

    void That(int Expect, Compare<int>* Actual)
    {
        Assert::That<int, int>(Expect, Actual);
    }

    void That(std::string Expect, Compare<const char*>* Acutal)
    {
        Assert::That<std::string, const char*>(Expect, Acutal);
    }
}

#endif // _ASSERT_HPP_