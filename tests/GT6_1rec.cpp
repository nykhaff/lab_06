#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/6_1rec.cpp"

TEST(GT6_1rec, CountElements) {
  int arr[] = {1, 2, -5, 40, 3, -15};
  int size = 6;

  EXPECT_EQ(el_count(arr, size, 0), 4);
}

TEST(GT6_1rec, SumElements) {
  int arr[] = {1, 2, -5, 40, 3, -15};
  int size = 6;

  EXPECT_EQ(el_sum(arr, size, 0), -16);
}

TEST(GT6_1rec, ReplaceElements) {
  int arr[] = {1, 2, -5, 40, 3, -15};
  int size = 6;

  replace(arr, size, 0);

  int expected[] = {0, 2, 0, 40, 0, 0};

  for (int i = 0; i < size; i++) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}