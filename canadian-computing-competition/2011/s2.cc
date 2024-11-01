#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    size_t N;
    cin >> N;

    vector<char> input(N);
    vector<char> answer(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    for (size_t i = 0; i < N; i++)
    {
        cin >> answer[i];
    }

    size_t score = 0;

    for (size_t i = 0; i < N; i++)
    {
        if (input[i] == answer[i])
        {
            score++;
        }
    }

    cout << score;

    return 0;
}
