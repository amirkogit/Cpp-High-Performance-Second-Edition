#include <cassert>
#include <gtest/gtest.h>
#include <vector>
#include <iostream>

//
// This example demonstrates how C++ can minimize
// heap allocations by:
// 1) Creating objects on the stack
// 2) Allocate multiple objects in one heap allocation
//

struct Car {
  int doors_{};
};

auto some_func() {
  auto num_doors = 2;
  auto car1 = Car{num_doors};
  auto car2 = Car{num_doors};
}

auto car_list() {
  const auto n = 7;
  auto cars = std::vector<Car>{};
  cars.reserve(n);
  for (size_t i = 0; i < n; ++i) {
    cars.push_back(Car{});
  }
}

TEST(HeapAllocations, Cars) {
  some_func();
  car_list();
  std::cout << "Test complete...\n";
}

void insertion_sort(std::vector<int>& a) {
  for (size_t i = 1; i < a.size(); ++i) {
    auto j = i;
    while (j > 0 && a[j - 1] > a[j]) {
      std::swap(a[j], a[j - 1]);
      --j;
    }
  }
}

TEST(InsertionSort, SortNumbers) {
  auto a = std::vector<int>{4, 2, 3, 1, 8, 5, 7, 6};

  insertion_sort(a);

  for (auto i : a) {
    std::cout << i << '\n';
  }

  for (size_t i = 1; i < a.size(); ++i) {
    ASSERT_TRUE(a[i - 1] < a[i]);
  }
}
