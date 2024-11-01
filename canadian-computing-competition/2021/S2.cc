// #include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// enum class Color
// {
//     kBlack,
//     kGold
// };

// void toggle(vector<vector<Color>> &canvas, int row, int column)
// {
//     if (canvas[row][column] == Color::kBlack)
//     {
//         canvas[row][column] = Color::kGold;
//     }
//     else
//     {
//         canvas[row][column] = Color::kBlack;
//     }
// }

int main()
{
    size_t M = 0, N = 0;
    cin >> M >> N;

    // vector<vector<size_t>> canvas(M, vector<size_t>(N, 0));

    unordered_map<size_t, size_t> row_operation_count;
    unordered_map<size_t, size_t> col_operation_count;

    int K = 0;
    cin >> K;

    for (int i = 0; i < K; ++i)
    {
        char direction = 0;
        cin >> direction;

        int target = 0;
        cin >> target;

        if (direction == 'R')
        {
            // for (size_t j = 0; j < N; ++j)
            // {
            //     // toggle(canvas, target - 1, j);
            //     ++canvas[target - 1][j];
            // }

            ++row_operation_count[target];
        }
        else
        {
            // for (size_t j = 0; j < M; ++j)
            // {
            //     // toggle(canvas, j, target - 1);
            //     ++canvas[j][target - 1];
            // }

            ++col_operation_count[target];
        }
    }

    size_t gold_count = 0;

    for (size_t row = 1; row <= M; ++row)
    {
        for (size_t col = 1; col <= N; ++col)
        {
            if ((row_operation_count[row] + col_operation_count[col]) % 2 != 0)
            {
                ++gold_count;
            }
        }
    }

    // for (const auto &row : canvas)
    // {
    //     for (const auto col : row)
    //     {
    //         if (col % 2 != 0)
    //         {
    //             ++gold_count;
    //         }
    //     }
    // }

    cout << gold_count;

    return 0;
}
