#include <iostream>
#include <set>
#include <string>

class Solution {
public:
  int firstUniqChar(std::string s) {
    int size = s.size();
    std::set<char> set;
    if (size == 1) {
      return 0;
    }
    for (int i = 0; i < size - 1; ++i) {
      char current = s.at(i);
      if (set.find(current) != set.end()) {
        continue;
      }
      set.insert(current);
      std::string sub = s.substr(i + 1, s.size());
      if (sub.find(current) == std::string::npos) {
        return i;
      }
    }
    char last = s.at(size -1);
    if (set.find(last) == set.end()) {
      return size - 1;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  std::cout << "caca\n";

  return 0;
}
