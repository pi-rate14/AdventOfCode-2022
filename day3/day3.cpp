#include <bits/stdc++.h>

int main()
{
    std::string rucksack;

    std::unordered_set<char> st;

    std::unordered_map<char, int> priorityMap;

    int x = 1;
    for (char i = 'a'; i <= 'z'; i++)
    {
        priorityMap[i] = x++;
    }

    for (char i = 'A'; i <= 'Z'; i++)
    {
        priorityMap[i] = x++;
    }

    int total = 0;

    while (std::cin >> rucksack)
    {
        std::unordered_map<char, bool> visited;

        std::string firstHalf = rucksack.substr(0, rucksack.size() / 2);
        std::string secondHalf = rucksack.substr(rucksack.size() / 2, rucksack.size());

        for (auto c : firstHalf)
        {
            visited[c] = true;
        }

        for (auto c : secondHalf)
        {
            if (visited[c])
            {
                total += priorityMap[c];
                break;
            }
        }
    }

    std::cout << total;
}