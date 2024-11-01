#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

namespace
{
    void print(const std::vector<std::vector<int>> &input)
    {
        for (const std::vector<int> &i : input)
        {
            for (const int &j : i)
            {
                std::clog << j << " ";
            }
            std::clog << "\n";
        }
        std::clog << std::endl;
    }
}

int main()
{
    // get input: proved working
    unsigned short n = 0;
    std::cin >> n;

    std::vector<std::vector<int>> drops;
    for (unsigned short i = 0; i < n; i++)
    {
        std::string inputln = "";
        std::cin >> inputln;

        int x = 0, y = 0, commaIndex = inputln.find(',');
        x = std::stoi(inputln.substr(0, commaIndex));
        y = std::stoi(inputln.substr(commaIndex + 1));
        drops.push_back({x, y});
    }

    int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
    for (const std::vector<int> &drop : drops)
    {
        minX = std::min(minX, drop[0]);
        minY = std::min(minY, drop[1]);
        maxX = std::max(maxX, drop[0]);
        maxY = std::max(maxY, drop[1]);
    }

    std::cout << minX - 1 << "," << minY - 1 << "\n"
              << maxX + 1 << "," << maxY + 1;

    return 0;
}