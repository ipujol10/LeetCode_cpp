#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums, int val) {
  int n = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums.at(i) != val) {
      n++;
    }
  }

  int i = 0, j = nums.size() - 1;
  while (i < j) {
    while (nums.at(i) != val && i < nums.size() - 1) {
      i++;
    }
    while (nums.at(j) == val && j > 0) {
      j--;
    }
    if (i < j) {
      int temp = nums.at(i);
      nums.at(i) = nums.at(j);
      nums.at(j) = temp;
    }
  }
  return n;
}

void check(std::vector<int> &nums, int val, int finalLength) {
  int k = removeElement(nums, val);
  if (k != finalLength) {
    std::cout << "Final length doesn't match\n";
    return;
  }
  for (int i = 0; i < k; i++) {
    if (nums.at(i) == val) {
      std::cout << "Unsorted element found\n";
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  // Example 1
  std::vector<int> ex1 = {3, 2, 2, 3};
  check(ex1, 3, 2);

  // Example 2
  std::vector<int> ex2 = {0, 1, 2, 2, 3, 0, 4, 2};
  check(ex2, 2, 5);

  std::cout << "Fininshed\n";

  return 0;
}
