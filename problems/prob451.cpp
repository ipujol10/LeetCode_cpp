#include <algorithm>
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  std::string frequencySort(std::string s) {
    std::map<char, int> freq;
    std::string out;
    for (char ch : s) {
      if (freq.find(ch) == freq.end()) {
        freq[ch] = 1;
      } else {
        freq[ch]++;
      }
    }

    while (!freq.empty()) {
      auto max = std::max_element(
          freq.begin(), freq.end(),
          [](const std::pair<char, int> &a, const std::pair<char, int> &b) {
            return a.second < b.second;
          });
      for (int i = 0; i < max->second; ++i) {
        out.push_back(max->first);
      }
      freq.erase(max->first);
    }

    return out;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout << "tree -> " << s.frequencySort("tree") << std::endl;
  std::cout << "cccaaa -> " << s.frequencySort("cccaaa") << std::endl;
  std::cout << "Aabb -> " << s.frequencySort("Aabb") << std::endl;

  return 0;
}
