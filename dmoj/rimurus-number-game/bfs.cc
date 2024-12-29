#include <deque>
#include <iostream>

int main(int argc, char const *argv[]) {
  int N = 0;
  std::cin >> N;

  size_t count = 0;

  std::deque<int> permutations{2, 3};

  while (!permutations.empty()) {
    ++count;

    const int front = permutations.front();
    permutations.pop_front();

    const int new_num_a = front * 10 + 2;
    const int new_num_b = new_num_a + 1;

    if (new_num_a <= N) {
      permutations.push_back(new_num_a);
    }

    if (new_num_b <= N) {
      permutations.push_back(new_num_b);
    }
  }

  std::cout << count;

  return 0;
}
