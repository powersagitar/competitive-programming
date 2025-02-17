#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  string g_str;
  cin >> g_str;

  int queries;
  cin >> queries;

  vector<pair<int, int>> ranges(queries);
  for (int i = 0; i < queries; ++i) {
    int lrange, rrange;
    cin >> lrange >> rrange;
    ranges[i] = make_pair(lrange, rrange);
  }

  vector<int> integrities(g_str.length(), 0);
  for (int i = 0; i < g_str.length(); ++i) {
    if (g_str[i] == 'G') {
      integrities[i] = 1;
    }
  }

  vector<int> integrities_psa(integrities.size() + 1, 0);
  for (int i = 0; i < integrities.size(); ++i) {
    integrities_psa[i + 1] = integrities_psa[i] + integrities[i];
  }

  for (const auto &[lrange, rrange] : ranges) {
    cout << integrities_psa[rrange + 1] - integrities_psa[lrange] << "\n";
  }

  return 0;
}
