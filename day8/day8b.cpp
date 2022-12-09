#include <bits/stdc++.h>
#include <ranges>

void printGrid(std::vector<std::vector<int>> &grid)
{
    for (auto x : grid)
    {
        for (auto y : x)
        {
            std::cout << y << " ";
        }

        std::cout << "\n";
    }
}

int main()
{
    std::ifstream inputFile("input.txt");

    std::string row;

    std::vector<std::vector<int>> grid;

    while (getline(inputFile, row))
    {
        std::vector<int> rows;
        for (auto c : row)
        {
            rows.push_back(int(c - '0'));
        }
        grid.push_back(rows);
    }

    // printGrid(grid);

    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<int>> vis(m, std::vector<int>(n, false));

    int maxi = -1;

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int curTree = grid[row][col];
            int offset = 1;
            int topVal = 0, bottomVal = 0, leftVal = 0, rightVal = 0;

            while ((row - offset >= 0) && grid[row - offset][col] < curTree)
            {
                topVal++;
                offset++;
            }
            if (row - offset >= 0)
            {
                topVal++;
            }

            offset = 1;

            while ((row + offset < m) && (grid[row + offset][col] < curTree))
            {
                bottomVal++;
                offset++;
            }
            if (row + offset < m)
            {
                bottomVal++;
            }

            offset = 1;

            while ((col - offset >= 0) && (grid[row][col - offset] < curTree))
            {
                leftVal++;
                offset++;
            }
            if (col - offset >= 0)
            {
                leftVal++;
            }

            offset = 1;

            while ((col + offset < n) && (grid[row][col + offset] < curTree))
            {
                rightVal++;
                offset++;
            }
            if (col + offset < n)
            {
                rightVal++;
            }

            offset = 1;

            int curVal = topVal * bottomVal * leftVal * rightVal;
            maxi = std::max(maxi, curVal);
        }
    }

    std::cout << "TOTAL SCORE: " << maxi << "\n";
};