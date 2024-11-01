#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::unordered_map<std::string, int> chart = 
    {
        {"Poblano", 1500},
        {"Mirasol", 6000},
        {"Serrano", 15500},
        {"Cayenne", 40000},
        {"Thai", 75000},
        {"Habanero", 125000}
    };

    int inputc = 0;
    std::cin >> inputc;
    std::vector<std::string> inputv;

    for (int i = 0; i < inputc; i++)
    {
        std::string inputln;
        std::cin >> inputln;
        inputv.push_back(inputln);
    }

    // main
    int result = 0;
    for (const std::string &chill : inputv)
    {
        result += chart[chill];
    }

    std::cout << result;
    
    return 0;
}