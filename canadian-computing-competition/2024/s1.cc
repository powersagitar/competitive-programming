#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; ++i)
    cin >> vec[i];

  int half = N / 2;

  int result = 0;

  for (int i = 0; i < half; ++i) {
    int opposite_pos = i + half;
    if (vec[i] == vec[opposite_pos])
      result += 2;
  }

  cout << result;
}