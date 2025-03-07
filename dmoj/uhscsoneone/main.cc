#include <iostream>
#include <vector>
using namespace std;

struct adj_t {
  int lrange;
  int rrange;
  int adj;
};

int main() {
  int friends;
  cin >> friends;

  vector<int> scores(friends);
  for (int i = 0; i < friends; ++i) {
    int score;
    cin >> score;
    scores[i] = score;
  }

  int adjs_num;
  cin >> adjs_num;

  vector<adj_t> adjs(adjs_num);
  for (int i = 0; i < adjs_num; ++i) {
    int lrange, rrange, adj;
    cin >> lrange >> rrange >> adj;
    adjs[i] = {lrange, rrange, adj};
  }

  return 0;
}
