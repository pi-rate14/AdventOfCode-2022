#include <bits/stdc++.h>

void printGrid(std::vector<std::vector<char>> &grid)
{
    std::cout << "\n\n\n";
    for (auto x : grid)
    {
        for (auto y : x)
        {
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}

std::vector<std::string> tokenize(std::string str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string word = "";
    for (auto c : str)
    {
        if (c == delimiter)
        {
            tokens.push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
    }
    tokens.push_back(word);
    return tokens;
}

bool spriteOverlaps(int sprite, int cycle)
{
    cycle %= 40;
    if (cycle - 1 == sprite || cycle == sprite || cycle + 1 == sprite)
    {
        return true;
    }

    return false;
}

int main()
{
    std::ifstream inputFile("input.txt");

    std::vector<std::string> rows;
    std::string row;

    while (getline(inputFile, row))
    {
        rows.push_back(row);
    }

    int cycleNumber = 0;
    int x = 1;

    std::vector<std::vector<char>> grid(6, std::vector<char>(40, ' '));
    int gridRow = 0;

    for (auto row : rows)
    {
        auto tokens = tokenize(row, ' ');

        std::string instruction = tokens[0];

        if (instruction == "noop")
        {

            spriteOverlaps(x, cycleNumber) ? 
                grid[gridRow][cycleNumber % 40] = '#' : 
                    grid[gridRow][cycleNumber % 40] = '.';

            printGrid(grid);
            cycleNumber++;
            if (cycleNumber % 40 == 0)
            {
                gridRow++;
            }

            spriteOverlaps(x, cycleNumber) ? 
                grid[gridRow][cycleNumber % 40] = '#' : 
                    grid[gridRow][cycleNumber % 40] = '.';
            
            printGrid(grid);
        }
        else
        {
            int val = std::stoi(tokens[1]);

            spriteOverlaps(x, cycleNumber) ? 
                grid[gridRow][cycleNumber % 40] = '#' : 
                    grid[gridRow][cycleNumber % 40] = '.';

            printGrid(grid);
            cycleNumber++;
            if (cycleNumber % 40 == 0)
            {
                gridRow++;
            }

            x += val;

            spriteOverlaps(x - val, cycleNumber) ? 
                grid[gridRow][cycleNumber % 40] = '#' : 
                    grid[gridRow][cycleNumber % 40] = '.';

            printGrid(grid);
            cycleNumber++;
            if (cycleNumber % 40 == 0)
            {
                gridRow++;
            }
        }
    }
}