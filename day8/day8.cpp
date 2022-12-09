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

    // mark horizontals
    for (int y = 0; y < m; y++)
    {
        int max = -1;
        for (int x = 0; x < n; x++)
        {
            if (grid[y][x] > max)
            {
                max = grid[y][x];
                vis[y][x] = true;
            }
        }
        max = -1;
        for (int x = n - 1; x >= 0; x--)
        {
            if (grid[y][x] > max)
            {
                max = grid[y][x];
                vis[y][x] = true;
            }
        }
    }

    // mark verticals
    for (int x = 0; x < n; x++)
    {
        int max = -1;
        for (int y = 0; y < m; y++)
        {
            if (grid[y][x] > max)
            {
                max = grid[y][x];
                vis[y][x] = true;
            }
        }
        max = -1;
        for (int y = m - 1; y >= 0; y--)
        {
            if (grid[y][x] > max)
            {
                max = grid[y][x];
                vis[y][x] = true;
            }
        }
    }

    int totalVisible = 0;

    for (auto y : vis)
    {
        for (auto x : y)
        {
            if (x == 1)
            {
                totalVisible++;
            }
        }
    }

    std::cout << "TOTAL VISIBLE: " << totalVisible << "\n";
};