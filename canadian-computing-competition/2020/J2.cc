#include <iostream>

int main()
{
    unsigned p = 0, n = 0, r = 0;
    std::cin >> p >> n >> r;

    unsigned day = 1, append = r * n;
    while (true)
    {
        n += append;
        append *= r;

        if (n > p)
        {
            break;
        }
        else
        {
            day++;
        }
    }
    
    std::cout << day;

    return 0;
}