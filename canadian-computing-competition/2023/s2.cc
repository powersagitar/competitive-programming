// editorial: https://dmoj.ca/problem/ccc23s2/editorial

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num_of_mounts = 0;
  cin >> num_of_mounts;

  vector<int> heights(num_of_mounts);
  for (int i = 0; i < num_of_mounts; ++i) {
    int height;
    cin >> height;
    heights[i] = height;
  }

  for (int window = 1; window <= num_of_mounts; ++window) {
    int window_min_score = INT_MAX;

    for (int offset = 0; offset <= num_of_mounts - window; ++offset) {
      int offset_score = 0;

      // bounds are inclusive
      for (int lbound = offset, rbound = offset + window - 1; lbound <= rbound;
           ++lbound, --rbound) {
        offset_score += abs(heights[rbound] - heights[lbound]);
      }

      window_min_score = min(window_min_score, offset_score);
    }

    cout << window_min_score << " ";
  }

  return 0;
}
