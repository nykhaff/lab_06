#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/6_2it.cpp"

TEST(GT6_2it, CountOddNumbers) {
  int arr[] = {1, 2, 3, 4, -5};
  int size = 5;

  EXPECT_EQ(count_odd(arr, size), 3);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}