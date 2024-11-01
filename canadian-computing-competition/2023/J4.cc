#include <iostream>
#include <vector>

namespace
{
    void print(const std::vector<std::vector<bool>> &input)
    {
        for (const auto &i : input)
        {
            for (const auto &j : i)
            {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }
        std::cout << "done\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    // input
    int c = 0;
    std::cin >> c;

    std::vector<std::vector<bool>> inputv;
    for (int i = 0; i < 2; i++)
    {
        std::string inputln;
        do
        {
            std::getline(std::cin, inputln);
        } while (inputln.empty());
        
        // std::clog << inputln.length() << "\n";

        std::vector<bool> assembler;

        // if performance issue occurs,
        // change the expression in condition to 
        // inputln.length()
        for (int j = 0; j < (c * 2) - 1; j += 2)
        {
            assembler.push_back((inputln[j] == '1') ? true : false);
        }
        inputv.push_back(assembler);
    }

    // main
    int tapeCount = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (inputv[i][j] == true)
            {
                tapeCount += 3;
            }

            int right = j + 1, down = i + 1;
            if (!(down == 1) || !(right < c))
            {
                continue;
            }

            if (inputv[i][right] == true)
            {
                tapeCount--;
            }
            if (inputv[down][j] == true && j % 2 != 0)
            {
                tapeCount--;
            }
        }
    }
    
    std::cout << tapeCount;

    return 0;
}