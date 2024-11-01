#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  // get input
  unsigned m = 0, n = 0;
  std::cin >> m >> n;

  std::vector<std::string> input;
  unsigned inputCount = 0;
  std::cin >> inputCount;
  for (unsigned i = 0; i < inputCount; i++) {
    std::string inputln = "";
    do {
      std::getline(std::cin, inputln);
    } while (inputln.empty());
    input.push_back(inputln);
  }

  // main process
  // initialize bool array to all false
  bool canvas[m][n];
  for (size_t r = 0; r < m; r++) {
    for (size_t c = 0; c < n; c++) {
      canvas[r][c] = false;
    }
  }

  // change color
  for (const std::string &inputln : input) {
    // use 0 based indexing
    unsigned number = std::stoul(inputln.substr(2)) - 1;

    switch (inputln[0]) {
    case 'R':
      for (unsigned c = 0; c < n; c++) {
        canvas[number][c] = !canvas[number][c];
      }
      break;

    case 'C':
      for (unsigned r = 0; r < m; r++) {
        canvas[r][number] = !canvas[r][number];
      }
      break;
    }
  }

  // count gold blocks
  unsigned goldCount = 0;
  for (unsigned r = 0; r < m; r++) {
    for (unsigned c = 0; c < n; c++) {
      if (canvas[r][c]) {
        goldCount++;
      }
    }
  }

  std::cout << goldCount;

  return 0;
}