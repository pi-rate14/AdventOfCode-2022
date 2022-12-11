#include <bits/stdc++.h>

std::unordered_map<int, int> checkMap{{20, 0}, {60, 0}, {100, 0}, {140, 0}, {180, 0}, {220, 0}};

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

    for (auto row : rows)
    {
        auto tokens = tokenize(row, ' ');
        std::string instruction = tokens[0];
        if (instruction == "noop")
        {
            cycleNumber++;
            if (checkMap.find(cycleNumber) != checkMap.end())
            {
                checkMap[cycleNumber] = cycleNumber * x;
            }
        }
        else
        {
            int val = std::stoi(tokens[1]);
            cycleNumber++;
            if (checkMap.find(cycleNumber) != checkMap.end())
            {
                checkMap[cycleNumber] = cycleNumber * x;
            }
            x += val;
            cycleNumber++;
            if (checkMap.find(cycleNumber) != checkMap.end())
            {
                checkMap[cycleNumber] = cycleNumber * (x - val);
            }
        }
    }

    int signalStrength = 0;
    for (auto sig : checkMap)
    {
        signalStrength += sig.second;
    }

    std::cout << signalStrength;
}