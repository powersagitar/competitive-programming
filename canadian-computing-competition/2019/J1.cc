#include <iostream>

int main()
{
    unsigned short three = 0, two = 0, one = 0;

    std::cin >> three >> two >> one;
    unsigned apples = three * 3 + two * 2 + one;

    std::cin >> three >> two >> one;
    unsigned bananas = three * 3 + two * 2 + one;

    if (apples > bananas)
    {
        std::cout << "A";
    }
    else if (apples < bananas)
    {
        std::cout << "B";
    }
    else
    {
        std::cout << "T";
    }

    return 0;
}