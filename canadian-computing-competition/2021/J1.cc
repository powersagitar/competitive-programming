#include <iostream>

int main()
{
    unsigned short boilingTemp = 0;
    std::cin >> boilingTemp;
    
    unsigned short pressure = 5 * boilingTemp - 400;
    std::cout << pressure << "\n";

    if (pressure > 100)
    {
        std::cout << "-1";
    }
    else if (pressure < 100)
    {
        std::cout << "1";
    }
    else
    {
        std::cout << "0";
    }
    
    return 0;
}