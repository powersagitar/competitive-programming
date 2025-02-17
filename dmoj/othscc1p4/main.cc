// TODO: TLE

#include <iostream>
#include <vector>
using namespace std;

struct strat_t {
  int left;
  int right;
};

int main() {
  int num_robots, attack_range, times_to_use_ability;
  cin >> num_robots >> attack_range >> times_to_use_ability;

  // int num_robots = 10;
  // int attack_range = 2;
  // int times_to_use_ability = 3;

  vector<int> robots(num_robots, 0);
  for (int i = 0; i < num_robots; ++i) {
    int power;
    cin >> power;
    robots[i] = power;
  }

  // vector<int> robots{10, 1, 3, 2, 9, 9, 8, 9, 1, 1};

  vector<int> robots_psa(num_robots + 1, 0);
  for (int i = 0; i < num_robots; ++i) {
    robots_psa[i + 1] = robots[i] + robots_psa[i];
  }

  int max_destroyed_powers = 0;
  strat_t strat{.left = times_to_use_ability, .right = 0};

  for (; strat.right <= times_to_use_ability; --strat.left, ++strat.right) {
    // inclusive
    int lbound = 0;
    int rbound = num_robots - 1;

    int destroyed_powers = 0;

    for (int _ = 0; _ < strat.left; ++_) {
      int left_atk_bound = lbound + attack_range - 1;
      if (left_atk_bound >= rbound) {
        // destroyed all robots
        destroyed_powers = robots_psa[num_robots];
        break;
      }

      destroyed_powers += robots_psa[left_atk_bound + 1] - robots_psa[lbound];
      lbound += attack_range;
    }

    if (destroyed_powers == robots_psa[num_robots]) {
      max_destroyed_powers = destroyed_powers;
      break;
    }

    for (int _ = 0; _ < strat.right; ++_) {
      int right_atk_bound = rbound - attack_range + 1;
      if (right_atk_bound <= lbound) {
        destroyed_powers = robots_psa[num_robots];
        break;
      }

      destroyed_powers += robots_psa[rbound + 1] - robots_psa[right_atk_bound];
      rbound -= attack_range;
    }

    max_destroyed_powers = max(destroyed_powers, max_destroyed_powers);

    if (max_destroyed_powers >= robots_psa[num_robots]) {
      break;
    }
  }

  cout << max_destroyed_powers;

  return 0;
}
