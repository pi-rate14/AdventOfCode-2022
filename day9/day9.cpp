#include <bits/stdc++.h>

// change knot size to 2 for part a solution
const int KNOT_SIZE = 10;

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

struct Point
{
    int row{};
    int col{};
};

int main()
{

    std::ifstream inputFile("input.txt");

    std::vector<std::pair<char, int>> moves;
    std::string row;

    while (getline(inputFile, row))
    {
        std::vector<std::string> tokens = tokenize(row, ' ');
        std::pair<char, int> move = {tokens[0][0], stoi(tokens[1])};
        moves.push_back(move);
    }

    std::vector<Point> points(KNOT_SIZE);
    std::unordered_set<std::string> pointSet;
    pointSet.insert("0,0");

    auto const movePoints{
        [&]
        {
            for (auto point{1}; point < points.size(); ++point)
            {
                auto const &head{points[point - 1]};
                auto &tail{points[point]};

                if (tail.row + 1 < head.row)
                {
                    ++tail.row;
                    if (tail.col < head.col)
                    {
                        ++tail.col;
                    }
                    else if (tail.col > head.col)
                    {
                        --tail.col;
                    }
                }
                else if (head.row + 1 < tail.row)
                {
                    --tail.row;
                    if (tail.col < head.col)
                    {
                        ++tail.col;
                    }

                    else if (tail.col > head.col)
                    {
                        --tail.col;
                    }
                }
                else if (tail.col + 1 < head.col)
                {
                    ++tail.col;
                    if (tail.row < head.row)
                    {
                        ++tail.row;
                    }

                    else if (tail.row > head.row)
                    {
                        --tail.row;
                    }
                }
                else if (head.col + 1 < tail.col)
                {
                    --tail.col;
                    if (tail.row < head.row)
                    {
                        ++tail.row;
                    }

                    else if (tail.row > head.row)
                    {
                        --tail.row;
                    }
                }
            }
            std::string toInsert = std::to_string(points.back().row) + "," + std::to_string(points.back().col);
            pointSet.insert(toInsert);
        }};

    for (auto move : moves)
    {
        char direction = move.first;
        int value = move.second;

        switch (direction)
        {
        case 'U':
            while (value--)
            {
                ++points[0].col;
                movePoints();
            }
            break;
        case 'D':
            while (value--)
            {
                --points[0].col;
                movePoints();
            }
            break;
        case 'L':
            while (value--)
            {
                --points[0].row;
                movePoints();
            }
            break;
        case 'R':
            while (value--)
            {
                ++points[0].row;
                movePoints();
            }
            break;
        }
    }

    std::cout << pointSet.size();
}