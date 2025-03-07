#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
  os << "pair: (" << p.first << ", " << p.second << ")\n";
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s) {
  for (const auto &elem : s) {
    os << elem << "\n";
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "vector:\n";

  for (const auto &e : v) {
    os << e << " ";
  }

  os << "\n";

  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &s) {
  os << "unordered_set:\n";

  for (const auto &e : s) {
    os << e << " ";
  }

  os << "\n";

  return os;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<T, U> &m) {
  os << "unordered_map:\n";

  for (const auto &e : m) {
    os << e.first << " -> " << e.second << "\n";
  }

  return os;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::map<T, U> &m) {
  os << "map:\n";

  for (const auto &e : m) {
    os << e.first << " -> " << e.second << "\n";
  }

  return os;
}
