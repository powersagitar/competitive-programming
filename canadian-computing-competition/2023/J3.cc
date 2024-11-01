#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // input
    int n = 0;
    std::cin >> n;

    std::vector<std::string> inputv;
    for (int i = 0; i < n; i++)
    {
        std::string inputln;
        std::cin >> inputln;
        inputv.push_back(inputln);
    }

    // main
    int maxAttendance = 0;
    std::vector<int> maxAttendanceDay = {1};
    for (int c = 0; c < 5; c++)
    {
        int attendance = 0;
        for (const std::string &day : inputv)
        {
            if (day[c] == 'Y')
            {
                attendance++;
            }
        }
        if (attendance > maxAttendance)
        {
            maxAttendance = attendance;
            maxAttendanceDay[0] = c + 1;
        }
        else if (attendance == maxAttendance)
        {
            maxAttendanceDay.push_back(c + 1);
        }
    }

    for (int i = 0; i < maxAttendanceDay.size() - 1; i++)
    {
        std::cout << maxAttendanceDay[i] << ",";
    }
    std::cout << *(maxAttendanceDay.rbegin());

    return 0;
}