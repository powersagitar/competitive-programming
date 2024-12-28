#include <iostream>

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;

    unsigned count = 0;

    for (int decrement_of_4 = 0; decrement_of_4 <= N; decrement_of_4 += 4)
    {
        const int multiple_of_5 = N - decrement_of_4;

        if (multiple_of_5 % 5 == 0) {
            ++count;
        }
    }

    std::cout << count;

    return 0;
}
