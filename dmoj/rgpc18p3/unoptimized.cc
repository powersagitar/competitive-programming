#include <iostream>
#include <vector>
using namespace std;

namespace {
void plus_minus(vector<int> &diff, const int left_idx, const int right_idx,
                const int magnitude) {
  diff[left_idx] += magnitude;

  if (right_idx + 1 < diff.size()) {
    diff[right_idx + 1] -= magnitude;
  }
}
} // namespace

int main() {
  int N = 0, T = 0;
  cin >> N >> T;

  vector<int> diff(N, 0);

  for (int i = 0; i < T; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    plus_minus(diff, a - 1, b - 1, c);
  }

  vector<int> psa(N, 0);
  psa.front() = diff.front();

  for (int i = 1; i < N; ++i) {
    psa[i] = psa[i - 1] + diff[i];
  }

  int L = 0;
  cin >> L;

  int max = 1;
  bool flag = true;

  // todo: to be optimized
  while (flag) {
    flag = false;

    for (int i = 0; i < N - max + 1; ++i) {
      // clog << "max " << max << ": ";

      int sweetness = 0;

      for (int j = i; j < i + max; ++j) {
        // clog << j << " ";

        sweetness += psa[j];
      }

      // clog << " sweetness: " << sweetness;
      // clog << "\n";

      if (sweetness <= L) {
        flag = true;
        ++max;
        break;
      }
    }
  }

  cout << --max;

  return 0;
}
