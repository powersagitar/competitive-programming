#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string str;
    std::getline(std::cin, str);

    std::string out = "(";

    int limit = str.length() - 4;

    for (int i = 2; i < limit; ++i)
    {
        const char c = str[i];

        switch (c)
        {
        case 'a':
            out += "car ";
            break;

        case 'd':
            out += "cdr ";
            break;
        }

        if (i != limit - 1) {
            out += "(";
        }
    }

    out += "x";

    for (int i = 0; i < str.length() - 6; ++i)
    {
        out += ")";
    }

    std::cout << out << "\n";

    return 0;
}
