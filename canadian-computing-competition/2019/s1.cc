#include <bits/stdc++.h>
using namespace std;

int main()
{
    array<array<short, 2>, 2> grid = {{{1, 2}, {3, 4}}};

    string input;
    cin >> input;

    for (char i : input)
    {
        switch (i)
        {
        case 'H':
            swap(grid[0][0], grid[1][0]);
            swap(grid[0][1], grid[1][1]);
            break;

        case 'V':
            swap(grid[0][0], grid[0][1]);
            swap(grid[1][0], grid[1][1]);
            break;
        }
    }

    cout << grid[0][0] << " " << grid[0][1] << "\n"
         << grid[1][0] << " " << grid[1][1];

    return 0;
}