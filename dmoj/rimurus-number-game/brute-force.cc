#include <iostream>
#include <string_view>
#include <string>

namespace
{
    bool ContainsOnlyTwoThree(std::string_view str)
    {
        for (const char c : str)
        {
            if (c != '2' && c != '3')
            {
                return false;
            }
        }

        return true;
    }
}

int main(int argc, char const *argv[])
{
    int N = 0;
    std::cin >> N;

    unsigned count = 0;

    for (int num = 2; num <= N; ++num)
    {
        std::string num_str = std::to_string(num);

        if (ContainsOnlyTwoThree(num_str))
        {
            ++count;
        }
    }

    std::cout << count;

    return 0;
}
