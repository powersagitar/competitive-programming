#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::cout.sync_with_stdio(false);

    // get input
    std::string input = "";
    do
    {
        std::getline(std::cin, input);
    } while (input.empty());

    bool prevNum = false;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '+')
        {
            std::cout << " tighten ";
        }
        else if (input[i] == '-')
        {
            std::cout << " loosen ";
        }
        else if (std::regex_match(std::to_string(input[i]), std::regex("4[8-9]|5[0-7]"))) // the ascii reference between '0' and '9'
        {
            std::cout << input[i];
            prevNum = true;
        }
        else // character is [A-Z]
        {
            if (prevNum)
            {
                std::cout << "\n";
                prevNum = false;
            }
            std::cout << input[i];
        }
    }

    return 0;
}