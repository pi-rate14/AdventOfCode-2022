#include <bits/stdc++.h>

bool isWin(char o, char p)
{
    return (o == 'A' && p == 'Y') || (o == 'B' && p == 'Z') || (o == 'C' && p == 'X');
}

char makeDecision(char move, char decision)
{
    switch (decision)
    {
    case 'X':
        if (move == 'A')
            return 'C';
        if (move == 'B')
            return 'A';
        if (move == 'C')
            return 'B';
        break;

    case 'Z':
        if (move == 'A')
            return 'B';
        if (move == 'B')
            return 'C';
        if (move == 'C')
            return 'A';
        break;

    case 'Y':
        return move;
        break;
    }
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

    std::unordered_map<char, int> decision{
        {'X', 0},
        {'Y', 3},
        {'Z', 6},
    };

    char decisionMove, opponentMove;

    while (std::cin >> opponentMove >> decisionMove)
    {
        total += decision[decisionMove];
        char playerMove = makeDecision(opponentMove, decisionMove);
        // std::cout << "opponent played: " << opponentMove << "\nDecision needed: " << decisionMove << "\nPlayer played: " << playerMove << "\n";
        total += opponent[playerMove];
        // total += opponent[makeDecision(opponentMove, decisionMove)];
    }

    std::cout << total;
}