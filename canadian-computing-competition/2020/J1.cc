#include <iostream>

int main()
{
    unsigned short small = 0, medium = 0, large = 0;
    std::cin >> small >> medium >> large;

    unsigned happiness = small + (2 * medium) + (3 * large);
    std::cout << ((happiness >= 10) ? "happy" : "sad");

    return 0;
}