#include <iostream>

int main()
{
    int regular = 0, small = 0;
    std::cin >> regular;
    std::cin >> small;
    std::cout << (regular * 8 + small * 3) - 28;

    return 0;
}