// #include "utils.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  size_t number_of_marks;
  cin >> number_of_marks;

  set<size_t> mark_indices_90;
  for (size_t i = 0; i < number_of_marks; ++i) {
    size_t mark;
    cin >> mark;
    if (mark >= 90) {
      mark_indices_90.emplace(i);
    }
  }

  if (mark_indices_90.size() < 1) {
    cout << 0;
    return 0;
  }

  size_t number_of_ranges;
  cin >> number_of_ranges;

  // 0 based
  vector<pair<size_t, size_t>> ranges(number_of_ranges);
  for (size_t i = 0; i < number_of_ranges; ++i) {
    size_t lrange, rrange;
    cin >> lrange >> rrange;
    ranges[i] = make_pair(lrange - 1, rrange - 1);
  }

  size_t max_90_or_more{0};

  for (auto [lrange, rrange] : ranges) {
    auto actual_lrange =
        find_if(mark_indices_90.begin(), mark_indices_90.end(),
                [lrange](const size_t index) { return index >= lrange; });

    auto actual_rrange =
        find_if(mark_indices_90.rbegin(), mark_indices_90.rend(),
                [rrange](const size_t index) { return index <= rrange; });

    // clog << "range: " << lrange << "-" << rrange << "\n";
    // clog << "actual_lrange: " << *actual_lrange << "\n";
    // clog << "actual_rrange: " << *actual_rrange << "\n";

    const auto distance = [&actual_lrange, &actual_rrange]() -> size_t {
      auto distance = 0;

      while (*actual_lrange <= *actual_rrange) {
        ++distance;
        ++actual_lrange;
      }

      return distance;
    }();

    if (distance > max_90_or_more) {
      max_90_or_more = distance;
    }
  }

  // cout << "result:\n";
  cout << max_90_or_more;

  return 0;
}
