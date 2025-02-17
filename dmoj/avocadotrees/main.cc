#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int num_of_trees, num_of_ranges, max_height;
  cin >> num_of_trees >> num_of_ranges >> max_height;

  using height_t = int;
  using yield_t = int;
  vector<pair<height_t, yield_t>> trees(num_of_trees);

  for (int i = 0; i < num_of_trees; ++i) {
    int height, yield;
    cin >> height >> yield;
    trees[i] = make_pair(height, yield);
  }

  // 0 based
  vector<pair<int, int>> ranges(num_of_ranges);
  for (int i = 0; i < num_of_ranges; ++i) {
    int lrange, rrange;
    cin >> lrange >> rrange;
    ranges[i] = make_pair(lrange - 1, rrange - 1);
  }

  vector<int> obtainables(num_of_trees, 0);
  for (int i = 0; i < num_of_trees; ++i) {
    if (trees[i].first <= max_height) {
      obtainables[i] = trees[i].second;
    }
  }

  // turn obtainables into psa
  vector<int> obtainables_psa(num_of_trees + 1, 0);
  for (int i = 0; i < num_of_trees; ++i) {
    obtainables_psa[i + 1] = obtainables_psa[i] + obtainables[i];
  }

  int max_range_sum = 0;

  // range sum
  for (const auto &[lrange, rrange] : ranges) {
    int range_sum = obtainables_psa[rrange + 1] - obtainables_psa[lrange];
    max_range_sum = max(max_range_sum, range_sum);
  }

  cout << max_range_sum;

  return 0;
}
