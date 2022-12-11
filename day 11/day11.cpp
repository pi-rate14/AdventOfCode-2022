#include <bits/stdc++.h>

const int WORRY_FACTOR = 1;
const int NUM_OF_ROUNDS = 10000;

void printQueue(std::queue<long long int> q)
{
    while (!q.empty())
    {
        std::cout << " " << q.front();
        q.pop();
    }
}

std::vector<long long int> tokenize(std::string str)
{
    std::vector<long long int> vec;
    std::stringstream ss(str);

    for (int i; ss >> i;)
    {
        vec.push_back(i);
        if (ss.peek() == ',' || ss.peek() == ' ')
            ss.ignore();
    }

    return vec;
}

class Monkey
{
public:
    int monkeyID;
    std::queue<long long int> items;
    char operation;
    std::string value;
    int testFactor;
    int trueMonkey;
    int falseMonkey;

    Monkey()
    {
    }

    Monkey(int id, std::queue<long long int> itm, char op, std::string val, int fac, int tr, int fa)
    {
        monkeyID = id;
        items = itm;
        operation = op;
        value = val;
        testFactor = fac;
        trueMonkey = tr;
        falseMonkey = fa;
    }
};

void printMonkeys(std::vector<Monkey *> &monkeys)
{
    for (int i = 0; i < monkeys.size(); i++)
    {
        std::cout << "monkey number: " << monkeys[i]->monkeyID << "\n";
        std::cout << "items: ";

        printQueue(monkeys[i]->items);

        std::cout << "\noperation: " << monkeys[i]->operation << " " << monkeys[i]->value << "\n";
        std::cout << "test: divisible by " << monkeys[i]->testFactor << "\n";
        std::cout << "trueMonkey: " << monkeys[i]->trueMonkey << "\n";
        std::cout << "falseMonkey: " << monkeys[i]->falseMonkey << "\n";
        std::cout << "\n\n";
    }
}

void processInput(std::vector<Monkey *> &monkeys)
{
    std::ifstream inputFile("input.txt");

    std::vector<std::string> rows;
    std::string row;

    int blockOffset = 0;

    int id = 0;

    while (getline(inputFile, row))
    {
        rows.push_back(row);
        blockOffset++;

        if (blockOffset == 7)
        {

            blockOffset = 0;
            std::vector<long long int> startingItems = tokenize(rows[1].substr(rows[1].find(':') + 2));

            std::queue<long long int> items;

            for (auto i : startingItems)
            {
                items.push(i);
            }

            char operationChar = rows[2].substr(rows[2].find('d') + 2)[0];

            auto operationVal = rows[2].substr(rows[2].find('d') + 4);

            int testVal = std::stoi(rows[3].substr(rows[3].find('y') + 2));

            int trueMonkey = std::stoi(rows[4].substr(rows[4].find('y') + 2));

            int falseMonkey = std::stoi(rows[5].substr(rows[5].find('y') + 2));

            Monkey *monkey = new Monkey(id, items, operationChar, operationVal, testVal, trueMonkey, falseMonkey);

            monkeys.push_back(monkey);

            id++;
            rows.clear();
        }
    }

    std::vector<long long int> startingItems = tokenize(rows[1].substr(rows[1].find(':') + 2));

    std::queue<long long int> items;

    for (auto i : startingItems)
    {
        items.push(i);
    }
    char operationChar = rows[2].substr(rows[2].find('d') + 2)[0];

    auto operationVal = rows[2].substr(rows[2].find('d') + 4);

    int testVal = std::stoi(rows[3].substr(rows[3].find('y') + 2));

    int trueMonkey = std::stoi(rows[4].substr(rows[4].find('y') + 2));

    int falseMonkey = std::stoi(rows[5].substr(rows[5].find('y') + 2));

    Monkey *monkey = new Monkey(id, items, operationChar, operationVal, testVal, trueMonkey, falseMonkey);

    monkeys.push_back(monkey);
}

int main()
{
    std::vector<Monkey *> monkeys;
    processInput(monkeys);

    std::vector<int> inspectionMap(monkeys.size(), 0);

    for (int i = 0; i < NUM_OF_ROUNDS; i++)
    {
        for (auto monkey : monkeys)
        {
            int itemsSize = monkey->items.size();
            while (!monkey->items.empty())
            {
                long long int item = monkey->items.front();
                monkey->items.pop();
                inspectionMap[monkey->monkeyID]++;
                int opVal = monkey->value == "old" ? item : std::stoi(monkey->value);
                long long int operationResult;

                if (monkey->operation == '+')
                    operationResult = item + opVal;
                else
                    operationResult = item * opVal;
                long long int newWorryLevel = operationResult / WORRY_FACTOR;

                bool passesTest = newWorryLevel % monkey->testFactor == 0;

                passesTest ? 
                        monkeys[monkey->trueMonkey]->items.push(newWorryLevel)
                                : monkeys[monkey->falseMonkey]->items.push(newWorryLevel);
            }
        }
    }
    sort(inspectionMap.begin(), inspectionMap.end(), std::greater<int>());
    std::cout << inspectionMap[0] * inspectionMap[1];
}