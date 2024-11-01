#include <iostream>
#include <vector>
#include <utility>

int main()
{
    unsigned short inputCount = 0;
    std::cin >> inputCount;
    
    std::vector<std::pair<std::string, unsigned short>> stats;
    for (unsigned short i = 0; i < inputCount; i++)
    {
        std::string name = "";
        unsigned short bid = 0;

        std::cin >> name;
        std::cin >> bid;

        stats.push_back({name, bid});
    }

    unsigned short maxBidIndex = 0;
    for (unsigned short index = 0; index < inputCount; index++)
    {
        maxBidIndex = (std::get<1>(stats[maxBidIndex]) < std::get<1>(stats[index])) ? index : maxBidIndex;
    }

    std::cout << std::get<0>(stats[maxBidIndex]);
    return 0;
}