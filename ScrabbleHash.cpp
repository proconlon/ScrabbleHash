#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int scrabbleHash(const std::string& word) {
    // map of scrabble scores
    std::map<char, int> scores = {
        {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1},
        {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8},
        {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1},
        {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1},
        {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4},
        {'Z', 10}
    };

    int sum = 0;
    for (char c : word) {
        char upperC = std::toupper(c);
        // add the score to the sum (as long as a valid character is used)
        if (scores.find(upperC) != scores.end()) {
            sum += scores[upperC];
        }
    }
    return sum;
}

int main() {
    // test cases
    std::string words[] = {"aqueous", "quaint", "qi", "quick", "query"};
    for (const std::string& word : words) {
        std::cout << "Scrabble hash for: \"" << word << "\" is " << scrabbleHash(word) << std::endl;
    }
    return 0;
}
