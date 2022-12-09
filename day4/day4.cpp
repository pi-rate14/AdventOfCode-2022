#include <bits/stdc++.h>

void processStringRow(std::string row, std::vector<int> &intRow)
{
    std::string word = "";
    for (int i = 0; i < row.size(); i++)
    {
        if (row[i] == '-' || row[i] == ',')
        {
            // std::cout << "word: " << word << "\n";
            if (word.size() != 0)
                intRow.push_back(stoi(word));
            word = "";
            continue;
        }

        word += row[i];
        if (i == row.size() - 1)
        {
            intRow.push_back(stoi(word));
        }
    }
}

bool overlaps(int lowFirst, int highFirst, int lowSecond, int highSecond)
{
    if (highSecond - highFirst >= 0 && lowFirst - lowSecond >= 0)
    {
        return true;
    }
    return false;
}

bool part2(int lowFirst, int highFirst, int lowSecond, int highSecond)
{
    if (lowFirst <= highSecond && lowSecond <= highFirst)
    {
        return true;
    }
    return false;
}

int main()
{

    std::string row;

    int total = 0, total2 = 0;

    while (std::cin >> row)
    {
        std::vector<int> intRow;
        processStringRow(row, intRow);

        // for (auto i : intRow)
        // {
        //     std::cout << i << " ";
        // }

        bool first = overlaps(intRow[0], intRow[1], intRow[2], intRow[3]);
        bool second = overlaps(intRow[2], intRow[3], intRow[0], intRow[1]);

        if (first || second)
        {
            total++;
        }

        first = part2(intRow[0], intRow[1], intRow[2], intRow[3]);
        second = part2(intRow[2], intRow[3], intRow[0], intRow[1]);

        if (first || second)
        {
            total2++;
        }
    }

    std::cout << "part1 ans: " << total << "\n";
    std::cout << "part2 ans: " << total2 << "\n";
}