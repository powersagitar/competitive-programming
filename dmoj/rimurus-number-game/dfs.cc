#include <iostream>

void dfs(long long current, long long N, size_t &count) {
  // If the current number is greater than N, stop the recursion
  if (current > N) {
    return;
  }

  // If current is less than or equal to N, it is a valid number
  ++count;

  // Generate the next numbers by appending 2 and 3
  dfs(current * 10 + 2, N, count);
  dfs(current * 10 + 3, N, count);
}

int main() {
  long long N = 0; // N can be as large as 10^18, so we use long long
  std::cin >> N;

  size_t count = 0;

  // Start DFS with initial numbers 2 and 3
  dfs(2, N, count);
  dfs(3, N, count);

  std::cout << count << std::endl;

  return 0;
}
