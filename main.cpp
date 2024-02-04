#include <iostream>
#include <vector>
#include <cstring>

using vector2d = std::vector<std::vector<size_t>>;

inline size_t get_elem(const vector2d & matrix, size_t row_idx, size_t col_idx)
{
    if(matrix.size() < row_idx || matrix[0].size() < col_idx || col_idx < 1 || row_idx < 1)
        throw std::logic_error("Out of matrix range");
    return matrix[row_idx - 1][col_idx - 1];
}

inline vector2d create_matrix(size_t row, size_t column)
{
    if(row < 1 || row > 50 || column < 1 || column > 50)
        std::logic_error("row and column must be more than 0 and less than 51");

    vector2d matrix(row, std::vector<size_t>(column));
    for(size_t i = 0; i < row; i++)
    {
        size_t offset = (column - 1) * (i % 2);
        for(size_t j = 0; j < column; j++)
        {
            matrix[i][j] = i * column + offset;
            offset = i % 2 == 1? offset - 1 : offset + 1;
        }
    }
    return matrix;
}
// cmd format (./matrix_searh <row> <column> <row_idx> <col_idx>)
int main(int argc, char **argv)
{
    try
    {
        if(argc == 5)
        {
            size_t row = std::stoul(argv[1]);
            size_t column = std::stoul(argv[2]);
            auto matrix = create_matrix(row, column);
            for(const auto & i : matrix)
            {
                for(const auto & j : i)
                {
                    std::cout << j << " ";
                }
                std::cout << "\n";
            }
            size_t row_idx = std::stoul(argv[3]);
            size_t col_idx = std::stoul(argv[4]);
            size_t result = get_elem(matrix, row_idx, col_idx);
            std::cout << "RESULT: " << result << "\n";
        }
        else
        {
            throw std::logic_error("Number of args must be 5");
        }
    }
    catch(const std::exception & except)
    {
        std::cout << "ERROR: " << except.what() << "\n";
    }
    return 0;
}