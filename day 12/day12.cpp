#include <bits/stdc++.h>

void printGrid(std::vector<std::vector<int>> &grid)
{
    for (auto x : grid)
    {
        for (auto y : x)
        {
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}

void printAdjList(std::vector<std::vector<int>> &adjList)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        std::cout << i << " : ";
        for (auto x : adjList[i])
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<int>> processInput(int &source, int &destination)
{
    std::ifstream inputFile("input.txt");

    std::vector<std::vector<int>> grid;
    std::string row;

    int ctr = 0;

    while (getline(inputFile, row))
    {
        std::vector<int> temp;
        for (auto c : row)
        {
            if (c == 'S')
            {
                source = ctr;
                temp.push_back(0);
                ctr++;
                continue;
            }

            if (c == 'E')
            {
                destination = ctr;
                temp.push_back(25);
                ctr++;
                continue;
            }

            temp.push_back(c - 'a');
            ctr++;
        }

        grid.push_back(temp);
    }

    return grid;
}

std::vector<std::vector<int>> makeAdjList(std::vector<std::vector<int>> const &grid)
{
    int height = grid.size(), width = grid[0].size();

    int rowvec[4] = {-1, 0, 1, 0};
    int colvec[4] = {0, -1, 0, 1};

    std::vector<std::vector<int>> adjList(height * width);

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + rowvec[i];
                int ncol = col + colvec[i];
                if (nrow >= 0 && nrow < height && ncol >= 0 && ncol < width && grid[nrow][ncol] - grid[row][col] <= 1)
                {
                    int key = row * width + col;
                    int val = nrow * width + ncol;
                    adjList[key].push_back(val);
                }
            }
        }
    }

    return adjList;
}

int main()
{

    int source = 0, destination = 0;
    std::vector<std::vector<int>> adjList = makeAdjList(processInput(source, destination));

    std::priority_queue<std::pair<int, int>> priorityQ;
    priorityQ.push({0, source});
    std::vector<int> distance(adjList.size(), 1e9);

    while (!priorityQ.empty())
    {
        int nodeDistance = priorityQ.top().first;
        int node = priorityQ.top().second;
        priorityQ.pop();

        for (auto adjNode : adjList[node])
        {
            if (nodeDistance + 1 < distance[adjNode])
            {
                distance[adjNode] = nodeDistance + 1;
                priorityQ.push({distance[adjNode], adjNode});
            }
        }
    }

    std::cout << distance[destination] << "\n";
}