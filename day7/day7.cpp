#include <bits/stdc++.h>
#include <ranges>
using namespace ::std;

struct File
{
    std::string filePath;
    long size = 0;
};

struct Directory
{
    std::string dirPath;
    long size = -1;
    std::unordered_set<std::string> childDirs;
    std::unordered_set<std::string> childFiles;
};

// std::vector<std::string> tokenize(std::string, std::string);
// long dirSize(Directory, std::unordered_map<std::string, File>, std::unordered_map<std::string, Directory>);

long dirSize(Directory &directory, std::unordered_map<std::string, File> &files, std::unordered_map<std::string, Directory> &directories)
{
    if (directory.size >= 0)
    {
        return directory.size;
    }

    long totalSizeOfFiles = 0;

    for (auto file : directory.childFiles)
    {
        totalSizeOfFiles += files[file].size;
    }

    long totalSizeOfDirs = 0;

    for (auto dir : directory.childDirs)
    {
        totalSizeOfDirs += dirSize(directories[dir], files, directories);
    }
    // std::cout << "DIR: " << directory.dirPath << " totalSize: " << totalSizeOfFiles + totalSizeOfDirs << "\n";

    return directory.size = totalSizeOfFiles + totalSizeOfDirs;
}

std::vector<std::string> tokenize(std::string str, std::string delimiter)
{
    std::vector<std::string> tokens;
    std::string word = "";
    for (auto c : str)
    {
        if (c == ' ')
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

    std::unordered_map<std::string, Directory> directories;
    directories["/"] = Directory{"/"};

    std::unordered_map<std::string, File> files;

    std::vector<std::string> pwd;
    pwd.push_back("/");

    for (std::string row : rows)
    {
        auto tokens = tokenize(row, " ");
        // std::cout << tokens[0] << " " << tokens[1] << "\n";
        if (tokens[0] == "$")
        {
            if (tokens[1] == "ls")
            {
                continue;
            }
            else
            {
                if (tokens[1] != "cd")
                {
                    std::cout << "crashed";
                }

                auto targetDir = tokens[2];

                if (targetDir == "/")
                {
                    pwd.clear();
                    pwd.emplace_back("/");
                }
                else if (targetDir == "..")
                {
                    pwd.pop_back();
                }
                else
                {
                    auto newPwd = pwd.back() + targetDir + "/";
                    pwd.emplace_back(newPwd);
                }

                // std::cout << pwd.back() << "\n";
            }
        }
        else
        {
            auto &parentDir = directories.at(pwd.back());
            if (tokens[0] == "dir")
            {
                auto path = pwd.back() + tokens[1] + "/";

                if (directories.find(path) == directories.end())
                {
                    directories[path] = Directory{path};
                }

                parentDir.childDirs.insert(path);
            }
            else
            {
                auto path = pwd.back() + tokens[1];
                if (files.find(path) == files.end())
                {
                    files[path] = File{path, std::stol(tokens[0])};
                }

                parentDir.childFiles.insert(path);
            }
        }
    }

    auto sizeOfRootDirectory = dirSize(directories["/"], files, directories);

    long filteramount = 0;
    for (auto itr : directories)
    {
        auto dir = itr.first;

        if (directories[dir].size <= 100000)
        {
            filteramount += directories[dir].size;
        }
    }

    std::cout << "FILTER VALUE: " << filteramount << "\n";
}
