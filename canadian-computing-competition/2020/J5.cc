#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    unsigned short m = 0, n = 0;
    std::cin >> m >> n;

    int rooms[m][n];
    for (unsigned short r = 0; r < m; r++)
    {
        std::string inputln = "";
        do
        {
            std::getline(std::cin, inputln);
        } while (inputln.empty());

        size_t startingIndex = 0;
        for (unsigned short c = 0; c < n; c++)
        {
            size_t endingIndex = inputln.find(' ', startingIndex);
            rooms[r][c] = std::stoi(inputln.substr(startingIndex, endingIndex - startingIndex));
            startingIndex = endingIndex + 1;
        }
    }

    // main process
    // solution: bfs
    std::vector<std::vector<int>> queue = {{1, 1}}; // this queue uses 1 based indexing
    std::vector<int> traversedProducts;
    while (queue.size())
    {
        unsigned short r = queue[0][0], c = queue[0][1];
        int product = rooms[r - 1][c - 1];
        // std::clog << "product: " << product << "\n";

        if (std::find(traversedProducts.begin(), traversedProducts.end(), product) != traversedProducts.end())
        {
            queue.erase(queue.begin());
            continue;
        }

        for (int firstMultiplier = 1; firstMultiplier <= product; firstMultiplier++)
        {
            if (product % firstMultiplier != 0)
            {
                continue;
            }
            int secondMultiplier = product / firstMultiplier;

            // std::clog << "first multiplier: " << firstMultiplier << "\nsecond multipiler: " << secondMultiplier << "\n\n";

            if (!(firstMultiplier <= m) || !(secondMultiplier <= n))
            {
                continue;
            }

            if (firstMultiplier == m && secondMultiplier == n)
            {
                std::cout << "yes";
                return 0;
            }
            queue.push_back({firstMultiplier, secondMultiplier});
        }
        traversedProducts.push_back(product);

        queue.erase(queue.begin());
    }
    std::cout << "no";

    return 0;
}