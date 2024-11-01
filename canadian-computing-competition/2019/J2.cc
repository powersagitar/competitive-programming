#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // get input
    unsigned l = 0;
    std::cin >> l;

    std::vector<std::vector<int>> input;
    for (size_t i = 0; i < l; i++)
    {
        std::string inputln;
        do
        {
            std::getline(std::cin, inputln);
        } while (inputln.empty());

        size_t divider = inputln.find(' ');
        int count = std::stoul(inputln.substr(0, divider));
        input.push_back({count, int(*inputln.rbegin())});
    }

    // main process
    for (const auto &vec : input)
    {
        std::cout << std::setw(vec[0]) << std::setfill(char(vec[1])) << char(vec[1]) << "\n";
    }

    return 0;
}