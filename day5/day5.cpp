#include <bits/stdc++.h>

void processRow(
    int source,
    int destination,
    int movementFactor,
    std::vector<std::stack<char>> &columnStacks)
{
    while (movementFactor--)
    {
        char top = columnStacks[source].top();
        columnStacks[source].pop();
        columnStacks[destination].push(top);
    }
}

void process2Row(
    int source,
    int destination,
    int movementFactor,
    std::vector<std::stack<char>> &columnStacks)
{

    std::stack<char> tempStack;
    while (movementFactor--)
    {
        char top = columnStacks[source].top();
        columnStacks[source].pop();
        tempStack.push(top);
    }

    while (!tempStack.empty())
    {
        char top = tempStack.top();
        tempStack.pop();
        columnStacks[destination].push(top);
    }
}

int main()
{
    std::ifstream inputFile("input.txt");

    std::string row;

    std::vector<std::string> rows;

    while (getline(inputFile, row))
    {
        rows.push_back(row);
    }

    int separator;
    for (int i = 0; i < rows.size(); i++)
    {
        if (!rows[i].size())
        {
            separator = i;
            break;
        }
    }

    std::string stackBaseLine = rows[separator - 1];

    std::vector<std::stack<char>> columnStacks;

    for (int i = 0; i < stackBaseLine.size(); i++)
    {
        if (stackBaseLine[i] == ' ')
        {
            continue;
        }

        std::stack<char> columnStack;

        for (int j = separator - 2; j >= 0; j--)
        {
            if (rows[j][i] == ' ')
                break;
            columnStack.push(rows[j][i]);
        }
        columnStacks.push_back(columnStack);
    }

    for (int i = separator + 1; i < rows.size(); i++)
    {
        std::stringstream stream(rows[i]);
        std::vector<std::string> intRow;
        std::string rowVal;

        while (getline(stream, rowVal, ' '))
        {
            intRow.push_back(rowVal);
        }

        int source = stoi(intRow[3]) - 1;
        int destination = stoi(intRow[5]) - 1;
        int movementFactor = stoi(intRow[1]);

        // processRow(source, destination, movementFactor, columnStacks);
        process2Row(source, destination, movementFactor, columnStacks);
    }

    for (auto st : columnStacks)
    {
        std::cout << st.top();
    }
}