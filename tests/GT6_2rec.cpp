#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/6_2rec.cpp"

TEST(GT6_2rec, CountOddNumbers) {
  int arr[] = {6, -7, 8, -9, -10, -11};
  int size = 6;

  EXPECT_EQ(count_odd(arr, size, 0), 3);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}