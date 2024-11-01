#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string t = "", s = "";
    std::cin >> t >> s;

    for (size_t i = 0; i < s.length(); i++)
    {
        // std::clog << "current s: " << s << "\n";
        size_t found = t.find(s);
        if (found != std::string::npos)
        {
            std::cout << "yes";
            return 0;
        }
        std::rotate(s.begin(), s.begin() + 1, s.end());
    }
    std::cout << "no";

    return 0;
}