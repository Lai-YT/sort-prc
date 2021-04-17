#include "quick_sort.hpp"

#include <cstdlib>
#include <gtest/gtest.h>
#include <vector>

class QuickSortTest : public ::testing::Test {
protected:
  void RanSet(std::vector<int>& arr) {
    for (int &n : arr) {
      n = std::rand() % (SIZE * 10);
    }
  }

  template<typename Container>
  bool CheckAscending(Container& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
      if (arr.at(i) < arr.at(i - 1)) {
        return false;
      }
    }
    return true;
  }

  void SetUp() override {
    std::srand(time(0));

    random_arr_1.resize(SIZE);
    RanSet(random_arr_1);
    random_arr_2.resize(SIZE);
    RanSet(random_arr_2);
    random_arr_3.resize(SIZE);
    RanSet(random_arr_3);

  }
  static constexpr int SIZE = 1000;
  std::vector<int> random_arr_1,
                   random_arr_2,
                   random_arr_3;
};

TEST_F(QuickSortTest, RandomTest1) {
  QuickSort(random_arr_1, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_1));
  QuickSort(random_arr_2, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_2));
  QuickSort(random_arr_3, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_3));
}


TEST_F(QuickSortTest, RandomTest2) {
  QuickSort(random_arr_1, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_1));
  QuickSort(random_arr_2, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_2));
  QuickSort(random_arr_3, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_3));
}


TEST_F(QuickSortTest, RandomTest3) {
  QuickSort(random_arr_1, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_1));
  QuickSort(random_arr_2, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_2));
  QuickSort(random_arr_3, 0, SIZE);
  ASSERT_TRUE(CheckAscending(random_arr_3));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
