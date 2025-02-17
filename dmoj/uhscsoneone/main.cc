#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct adj_t {
  int lrange;
  int rrange;
  int adj_factor;
};

int main() {
  int num_of_friends;
  cin >> num_of_friends;

  vector<int> scores(num_of_friends);
  for (int i = 0; i < num_of_friends; ++i) {
    int score;
    cin >> score;
    scores[i] = score;
  }

  int num_of_adjusts;
  cin >> num_of_adjusts;

  vector<adj_t> adjusts(num_of_adjusts);
  for (int i = 0; i < num_of_adjusts; ++i) {
    int lrange, rrange, adj_factor;
    cin >> lrange >> rrange >> adj_factor;
    adjusts[i] = {lrange - 1, rrange - 1, adj_factor};
  }

  vector<int> scores_diff_arr(num_of_friends, scores.front());
  for (int i = 1; i < num_of_friends; ++i) {
    scores_diff_arr[i] = scores[i] - scores[i - 1];
  }

  for (const auto &[lrange, rrange, adj_factor] : adjusts) {
    scores_diff_arr[lrange] += adj_factor;
    int psa_rrange = rrange + 1;
    if (psa_rrange < num_of_friends) {
      scores_diff_arr[psa_rrange] -= adj_factor;
    }
  }

  vector<int> new_scores(num_of_friends, scores_diff_arr.front());
  for (int i = 1; i < num_of_friends; ++i) {
    new_scores[i] = new_scores[i - 1] + scores_diff_arr[i];
  }

  int max_score = INT_MIN;
  for (const auto score : new_scores) {
    max_score = max(max_score, score);
    cout << score << " ";
  }
  cout << "\n" << max_score;

  return 0;
}
