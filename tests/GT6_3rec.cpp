#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/6_3rec.cpp"

TEST(GT6_3rec, SumEvenInt) {
  int arr[] = {1, 4, -50, 2, 3, 4, -5};
  int size = 7;

  EXPECT_EQ(sum_even(arr, size, 0), -40);
}

TEST(GT6_3rec, SumEvenLong) {
  long arr[] = {1, 4, -50, 2, 3, 4, -5};
  int size = 7;

  EXPECT_EQ(sum_even<long>(arr, size, 0), -40);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}