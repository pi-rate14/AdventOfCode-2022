#include <bits/stdc++.h>

char processPipeline(std::vector<std::string> pipeline)
{
    std::unordered_map<char, int> vis;
    for (auto rucksack : pipeline)
    {
        std::unordered_set<char> st(rucksack.begin(), rucksack.end());
        for (auto c : st)
        {
            vis[c]++;
            if (vis[c] == 3)
            {
                // std::cout << c << "is commmon\n";
                return c;
            }
        }
    }
}

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

    int lineCounter = 0;

    std::vector<std::string> pipeline;

    while (std::cin >> rucksack)
    {
        lineCounter++;
        pipeline.push_back(rucksack);
        if (lineCounter == 3)
        {
            total += priorityMap[processPipeline(pipeline)];
            pipeline.clear();
            lineCounter = 0;
        }
    }

    std::cout << total;
}