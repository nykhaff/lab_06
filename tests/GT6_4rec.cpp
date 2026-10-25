#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/6_4rec.cpp"

TEST(GT6_4rec, CalcProd) {
  int arr[] = {-1, 0, 5, 4, -6, 4, 5, 0, -5};
  int size = 9;

  EXPECT_EQ(even_i_product(arr, size, 0), -750);
}

TEST(GT6_4rec, FindZeros) {
  int arr[] = {-1, 0, 5, 4, -6, 4, 5, 0, -5};
  int size = 9;

  EXPECT_EQ(find_first_zero(arr, size, 0), 1);
  EXPECT_EQ(find_last_zero(arr, size, size - 1), 7);
}

TEST(GT6_4rec, SumBetZer) {
  int arr[] = {-1, 0, 5, 4, -6, 4, 5, 0, -5};
  int size = 9;

  int first = find_first_zero(arr, size, 0);
  int last = find_last_zero(arr, size, size - 1);

  EXPECT_EQ(sum_between_zeros(arr, first, last), 12);
}

TEST(GT6_4rec, Transform) {
  int arr[] = {-1, 0, 5, 4, -6, 4, 5, 0, -5};
  int size = 9;

  transform(arr, size, 0, false);

  int expected[] = {0, 5, 4, 4, 5, 0, -1, -6, -5};
  for (int i = 0; i < size; i++) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}