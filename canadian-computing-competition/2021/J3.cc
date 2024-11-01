#include <iostream>

int main()
{
    unsigned short previous = 0; // 0 is right, 1 is left
    while (true)
    {
        std::string input = "";
        std::cin >> input;

        if (input == "99999")
        {
            break;
        }

        unsigned short sum = int(input[0]) - '0' + int(input[1]) - '0';
        
        if (sum == 0)
        {
            switch (previous)
            {
                case 0:
                    std::cout << "right ";
                    break;
                case 1:
                    std::cout << "left ";
                    break;
            }
        }
        else
        {
            if (sum % 2 != 0) // sum is odd
            {
                previous = 1;
                std::cout << "left ";
            }
            else // sum is even
            {
                previous = 0;
                std::cout << "right ";
            }
        }

        std::cout << input.substr(2) << "\n";
    }

    return 0;
}