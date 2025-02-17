#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int num_of_tests;
  cin >> num_of_tests;

  vector<int> marks_above_90(num_of_tests);
  for (int i = 0; i < num_of_tests; ++i) {
    int mark;
    cin >> mark;
    if (mark >= 90) {
      marks_above_90[i] = 1;
    }
  }

  int num_of_ranges;
  cin >> num_of_ranges;

  vector<pair<int, int>> ranges(num_of_ranges);
  for (int i = 0; i < num_of_ranges; ++i) {
    int lrange, rrange;
    cin >> lrange >> rrange;
    ranges[i] = make_pair(lrange - 1, rrange - 1);
  }

  vector<int> marks_psa(num_of_tests + 1);
  for (int i = 0; i < num_of_tests; ++i) {
    marks_psa[i + 1] = marks_psa[i] + marks_above_90[i];
  }

  int max_tests = 0;

  for (const auto &[lrange, rrange] : ranges) {
    int tests = marks_psa[rrange + 1] - marks_psa[lrange];
    max_tests = max(max_tests, tests);
  }

  cout << max_tests;

  return 0;
}
