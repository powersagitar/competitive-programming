#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int number_of_masses;
  cin >> number_of_masses;

  vector<int> masses(number_of_masses);
  for (int i = 0; i < number_of_masses; ++i) {
    int mass;
    cin >> mass;
    masses[i] = mass;
  }

  int queries;
  cin >> queries;

  vector<pair<int, int>> ranges(queries);
  for (int i = 0; i < queries; ++i) {
    int lrange, rrange;
    cin >> lrange >> rrange;
    ranges[i] = make_pair(lrange, rrange);
  }

  // algo
  vector<int> psa(number_of_masses + 1);
  for (int i = 0; i < number_of_masses; ++i) {
    psa[i + 1] = psa[i] + masses[i];
  }

  for (const auto [lrange, rrange] : ranges) {
    cout << psa[rrange + 1] - psa[lrange] << "\n";
  }

  return 0;
}
