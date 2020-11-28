#ifndef _ASSERT_HPP_
#define _ASSERT_HPP_

#include <iostream>

enum Operator {
  Equal,
};

template <typename T>
class Compare {
 public:
  Compare(T& Value, Operator Op) : Value(Value), Op(Op) {}
  T Value;
  Operator Op;
};

template <typename T>
Compare<T>* Equals(T Value) {
  Operator op = Operator::Equal;
  return new Compare<T>(Value, op);
}

namespace Assert {

template <typename T1, typename T2>
void That(T1& Actual, Compare<T2>* Expect) {
  bool condition = false;
  switch (Expect->Op) {
    case Operator::Equal:
      condition = (Actual == Expect->Value);
      break;

    default:
      break;
  }

  if (condition) {
    std::cout << "PASS" << std::endl;
  } else {
    std::cout << "FAILED, Expect: " << Expect->Value << ", Actual: " << Actual
              << std::endl;
  }
}

void That(int Actual, Compare<int>* Expect) {
  Assert::That<int, int>(Actual, Expect);
}

void That(std::string Actual, Compare<const char*>* Expect) {
  Assert::That<std::string, const char*>(Actual, Expect);
}

}  // namespace Assert

#endif  // _ASSERT_HPP_