#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int arr_size;
  cin >> arr_size;

  vector<int> arr_a(arr_size);
  for (int i = 0; i < arr_size; ++i) {
    int n;
    cin >> n;
    arr_a[i] = n;
  }

  vector<int> arr_b(arr_size);
  unordered_map<int, int> ints_in_b;
  for (int i = 0; i < arr_size; ++i) {
    int n;
    cin >> n;
    arr_b[i] = n;
    ++ints_in_b[n];
  }

  bool possible = true;
  vector<string> swipes;

  for (int i = 0; i < arr_size; ++i) {
    if (arr_a[i] == arr_b[i]) {
      continue;
    }

    int target_index = i;
    int from_index = [arr_size, target_index, &arr_a, &arr_b]() {
      for (int i = 0; i < arr_size; ++i) {
        if (arr_a[i] == arr_b[target_index]) {
          return i;
        }
      }
      return -1;
    }();

    if (from_index < 0) {
      possible = false;
      break;
    }

    char direction = (from_index < target_index) ? 'R' : 'L';
    int magnitude = abs(target_index - from_index);

    if (direction == 'L') {
      for (int swipe_cnt = 0; swipe_cnt < magnitude; ++swipe_cnt) {
        // if (ints_in_b.count(arr_a[from_index - 1 - swipe_cnt]) > 0) {
        //   possible = false;
        //   break;
        // }

        if (ints_in_b.count(arr_a[from_index - 1 - swipe_cnt]) > 0) {
          --ints_in_b.at(arr_a[from_index - 1 - swipe_cnt]);
          if (ints_in_b.at(arr_a[from_index - 1 - swipe_cnt]) < 1) {
            possible = false;
            break;
          }
        }

        arr_a[from_index - 1 - swipe_cnt] = arr_a[from_index];
      }

      swipes.emplace_back("L " + to_string(target_index) + " " +
                          to_string(from_index));
    } else {
      for (int swipe_cnt = 0; swipe_cnt < magnitude; ++swipe_cnt) {
        // if (ints_in_b.count(arr_a[from_index + 1 + swipe_cnt]) > 0) {
        //   possible = false;
        //   break;
        // }

        if (ints_in_b.count(arr_a[from_index + 1 + swipe_cnt]) > 0) {
          --ints_in_b.at(arr_a[from_index + 1 + swipe_cnt]);
          if (ints_in_b.at(arr_a[from_index + 1 + swipe_cnt]) < 1) {
            possible = false;
            break;
          }
        }

        arr_a[from_index + 1 + swipe_cnt] = arr_a[from_index];
      }

      swipes.emplace_back("R " + to_string(from_index) + " " +
                          to_string(target_index));
    }

    if (!possible) {
      break;
    }
  }

  if (!possible) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n" << swipes.size() << "\n";
  for (const auto &s : swipes) {
    cout << s << "\n";
  }

  return 0;
}
