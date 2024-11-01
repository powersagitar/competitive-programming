#include <iostream>
#include <unordered_map>

int main() {
  unsigned T, N;
  std::cin >> T >> N;

  for (unsigned i = 0; i < T; ++i) {
    std::string current_str;
    std::cin >> current_str;

    std::unordered_map<char, unsigned> char_count;

    for (const auto &current_char : current_str)
      char_count[current_char]++;

    bool alternates = true;

    for (unsigned j = 0; j < N - 1; ++j) {
      const char current_char = current_str[j];
      const char next_char = current_str[j + 1];

      if (char_count.at(current_char) > 1) {
        if (char_count.at(next_char) != 1) {
          alternates = false;
          break;
        }
      } else {
        if (!(char_count.at(next_char) > 1)) {
          alternates = false;
          break;
        }
      }
    }

    if (alternates)
      std::cout << "T\n";
    else
      std::cout << "F\n";
  }

  return 0;
}