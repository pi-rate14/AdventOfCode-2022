#include <bits/stdc++.h>

bool isWin(char o, char p)
{
    return (o == 'A' && p == 'Y') || (o == 'B' && p == 'Z') || (o == 'C' && p == 'X');
}

int main()
{
    int total = 0;

    std::unordered_map<char, int> opponent{
        {'A', 1},
        {'B', 2},
        {'C', 3},
    };

    std::unordered_map<char, int> player{
        {'X', 1},
        {'Y', 2},
        {'Z', 3},
    };

    char playerMove, opponentMove;

    while (std::cin >> opponentMove >> playerMove)
    {
        total += player[playerMove];

        if (opponent[opponentMove] == player[playerMove])
        {
            total += 3;
        }
        else if (isWin(opponentMove, playerMove))
        {
            total += 6;
        }
    }

    std::cout << total;
}