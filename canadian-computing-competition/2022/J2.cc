#include <iostream>
#include <utility> // std::pair
#include <vector>

int main()
{
    unsigned memberNumber = 0;
    std::cin >> memberNumber;
    std::vector<std::pair<unsigned, unsigned>> status;
    for (unsigned i = 0; i < memberNumber; i++)
    {
        int points = 0, fouls = 0;
        std::cin >> points;
        std::cin >> fouls;
        status.push_back({points, fouls});
    }

    unsigned goldenPlayer = 0;
    for (auto &currentPlayer : status)
    {
        if (currentPlayer.first * 5 - currentPlayer.second * 3 > 40)
        {
            goldenPlayer++;
        }
    }

    std::cout << goldenPlayer << ((goldenPlayer == memberNumber) ? "+" : "");

    return 0;
}