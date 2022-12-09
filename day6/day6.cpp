#include <bits/stdc++.h>

int main() {

    const int WINDOW_SIZE = 14;

    std::ifstream inputFile("input.txt");

    char ch;

    std::vector<char> window;

    std::vector<char>::iterator start;

    int endMarker = 0, startMarker = -WINDOW_SIZE + 1;

    while (!inputFile.eof()) {
        
        endMarker++;
        startMarker++;

        inputFile.get(ch);
        window.push_back(ch);

        start = window.begin();

        int windowSize = std::distance(start + startMarker - 1, window.end());

        if (windowSize == WINDOW_SIZE && startMarker > 0) {
            std::unordered_set<char> st(start + startMarker - 1, window.end());

            if (st.size() == WINDOW_SIZE) {
                std::cout << endMarker;
                break;
            }
        }
    }
}
