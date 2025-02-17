#include <iostream>
using namespace std;

int main() {
  int vertices;
  cin >> vertices;

  // n choose 4
  long long result =
      (vertices - 3) * (vertices - 2) * (vertices - 1) * vertices;

  result /= 24;

  cout << result;

  return 0;
}
