#include <gtest/gtest.h>

// pow_n accepts any number type
template <typename T> 
auto pow_n(const T& v, int n) {
  auto product = T{1};
  for (int i = 0; i < n; ++i) {
    product *= v;
  }
  return product;
}

// template function to return n times the given number
template<typename T>
auto times_n(const T& v, int n) {
  return v * n;
}

TEST(TemplateFunction, PowN) {
  auto x = pow_n<float>(2.0f, 3); // x is a float
  ASSERT_FLOAT_EQ(8.0f, x);
  ASSERT_EQ(typeid(float), typeid(x));

  auto y = pow_n<int>(3, 3); // y is an int
  ASSERT_EQ(27, y);
  ASSERT_EQ(typeid(int), typeid(y));
}

TEST(TemplateFunction, TimesN) {
  auto x = times_n<int>(10, 3);
  ASSERT_EQ(30,x);
  ASSERT_EQ(typeid(int), typeid(x));

  auto y = times_n<float>(20.1, 2);
  ASSERT_FLOAT_EQ(40.2f, y);
  ASSERT_EQ(typeid(float), typeid(y));
}