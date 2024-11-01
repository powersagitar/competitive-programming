#include <iostream>
#include <vector>
#include <string>

namespace
{
    bool isInSelection(const std::vector<std::vector<unsigned>> &trees, const unsigned &x, const unsigned &y, const unsigned &side)
    {
        for (const auto &currentTree : trees)
        {
            if (currentTree[0] >= x && currentTree[0] < x + side && currentTree[1] >= y && currentTree[1] < y + side)
            {
                return true;
            }
        }
        return false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    // get input
    // get yard size
    unsigned canvasSide = 0;
    std::cin >> canvasSide;

    // get tree coordinates
    unsigned inputCount = 0;
    std::cin >> inputCount;
    std::vector<std::vector<unsigned>> trees;
    for (unsigned i = 0; i < inputCount; i++)
    {
        std::string inputln = "";
        do
        {
            std::getline(std::cin, inputln);
        } while (inputln.empty());

        unsigned divider = inputln.find(' ');
        unsigned x = stoul(inputln.substr(divider + 1));
        unsigned y = stoul(inputln.substr(0, divider));

        // make coordinates use 0 based indexing
        trees.push_back({x - 1, y - 1});
    }

    // main process: traverse through the yard
    for (unsigned currentSide = canvasSide; currentSide > 0; currentSide--)
    {
        for (unsigned y = 0; y <= canvasSide - currentSide; y++)
        {
            for (unsigned x = 0; x <= canvasSide - currentSide; x++)
            {
                if (!isInSelection(trees, x, y, currentSide))
                {
                    std::cout << currentSide;
                    return 0;
                }
            }
        }
    }

    return 0;
}