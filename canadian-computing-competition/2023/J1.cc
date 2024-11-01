#include <iostream>

int main()
{
    int p = 0, c = 0;
    std::cin >> p >> c;
    std::cout << (p * 50 - c * 10 + ((p > c) ? 500 : 0));
    return 0;
}