#include <iostream>
#include <vector>
using namespace std;

namespace {
void plus_minus(vector<int> &diff, const int left_idx, const int right_idx, const int magnitude) {
    diff[left_idx] += magnitude;

    if (right_idx + 1 < diff.size()) {
        diff[right_idx + 1] -= magnitude;
    }
}
}

int main() {
    int I = 0;
    cin >> I;

    int N = 0;
    cin >> N;

    int J = 0;
    cin >> J;

    vector<int> diff(I, 0);

    for (int i = 0; i < J; ++i) {
        int Xi = 0, Xf = 0, K = 0;
        cin >> Xi >> Xf >> K;

        plus_minus(diff, Xi - 1, Xf - 1, K);
    }

    vector<int> psa(I, 0);
    psa[0] = diff[0];

    for (int i = 1; i < psa.size(); ++i) {
        psa[i] = psa[i - 1] + diff[i];
    }

    int cnt = 0;

    for (int i = 0; i < psa.size(); ++i) {
        if (psa[i] < N) {
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
