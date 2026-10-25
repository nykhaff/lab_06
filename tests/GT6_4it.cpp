#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/6_4it.cpp"

TEST(GT6_4it, CalcProd) {
  int arr[] = {-1, 0, 5, 4, -6, 4, 5, 0, -5};
  int size = 9;

  EXPECT_EQ(calc_product(arr, size), -750);
}

TEST(GT6_4it, SumBetZer) {
  int arr[] = {-1, 0, 5, 4, -6, 4, 5, 0, -5};
  int size = 9;

  EXPECT_EQ(sum_between_zeros(arr, size), 12);
}

TEST(GT6_4it, Transform) {
  int arr[] = {-1, 0, 5, 4, -6, 4, 5, 0, -5};
  int size = 9;

  transform(arr, size);

  int expected[] = {0, 5, 4, 4, 5, 0, -1, -6, -5};
  for (int i = 0; i < size; i++) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}